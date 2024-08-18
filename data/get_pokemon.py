import requests
from bs4 import BeautifulSoup
import json


def get_all_moves():
    f = open("data/moves.json", "w")
    moves = {}
    r = requests.get(
        "https://pokemondb.net/move/generation/1")
    soup = BeautifulSoup(r.content, 'html.parser')
    rows = soup.find_all('tr')[1:]
    for move in rows:
        name_wrapper = move.find("td", {"class": "cell-name"})
        if name_wrapper is not None:
            name = name_wrapper.findChild("a").decode_contents()
        type_wrapper = move.find("td", {"class": "cell-icon"})
        if type_wrapper is not None:
            type = type_wrapper.findChild("a").decode_contents()
        category_wrapper = move.find("td", {"class": "cell-icon text-center"})
        if category_wrapper is not None:
            category = category_wrapper.findChild("img").get("title")
        numbers = move.find_all("td", {"class": "cell-num"})
        if numbers is not None:
            try:
                power = int(numbers[0].decode_contents())
            except:
                power = 'N/A'
            try:
                acc = int(numbers[1].decode_contents()) / 100
            except:
                acc = 'N/A'
            pp = numbers[2].decode_contents()
        desc = move.find("td", {"class": "cell-long-text"}).decode_contents()
        effect = bool(len(desc))
        data = {
            "name": name,
            "type": type,
            "category": category,
            "target": "Opponent",
            "power": power,
            "accuracy": acc,
            "pp": pp,
            "effect": effect
        }
        moves[name] = data
    json.dump(moves, f, indent=4)


def get_moveset(pokemon: str):
    moveset = []
    r = requests.get(
        f"https://bulbapedia.bulbagarden.net/wiki/{pokemon}_(Pok%C3%A9mon)/Generation_I_learnset#By_leveling_up")
    soup = BeautifulSoup(r.content, 'html.parser')
    table = soup.find(
        'table', attrs={"style": "border-collapse:collapse;"}).find_all('tr')[1:]

    for move in table:
        row = [x for x in list(move) if x != "\n"]
        if len(row) > 6:
            i = 1
            try:
                level_learned = int(row[i].decode_contents())
            except:
                continue
        else:
            i = 0
            try:
                level_learned = int(row[i].find('span').decode_contents())
            except:
                continue
        name = row[i+1].find('span').decode_contents()
        # print(f"{level_learned} - {name} - {type} - {power} - {acc} - {pp}")
        move_obj = {
            "name": name,
            "level": level_learned,
        }
        moveset.append(move_obj)
    return moveset


def get_stats():
    f = open("data/pokemon.json", "w")
    pokemon_data = {}
    r = requests.get(
        'https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_base_stats_(Generation_I)')
    soup = BeautifulSoup(r.content, 'html.parser')

    pokemon_list = list(soup.find_all(
        'tr', {"style": "background:#FFFFFF; text-align:center"}))

    for pokemon in pokemon_list:
        raw_data = list(pokemon)[4:]
        data = [x for x in raw_data if x != "\n"]
        name = data[0].contents[0].decode_contents()

        hp = data[1].contents[0].strip('\n')
        atk = data[2].contents[0].strip('\n')
        de = data[3].contents[0].strip('\n')
        spd = data[4].contents[0].strip('\n')
        spatk = data[5].contents[0].strip('\n')
        moveset = get_moveset(name)

        data = {
            "name": name,
            "bst": {
                "hp": hp,
                "atk": atk,
                "def": de,
                "spe": spatk,
                "spd": spd,
            },
            "moves": moveset,
        }
        pokemon_data[name] = data
        if name == 'Mew':
            break
    json.dump(pokemon_data, f, indent=4)


get_all_moves()
