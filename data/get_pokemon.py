import requests
from bs4 import BeautifulSoup

f = open("data/pokemon.json", "w")


class Move:
    def __init__(self, name, level):
        self.name = name
        self.level = level

    def print_move(self):
        print(f"Learns {self.name} at level {self.level}")


def get_all_moves():
    r = requests.get(
        "https://bulbapedia.bulbagarden.net/wiki/Category:Generation_I_moves")
    soup = BeautifulSoup(r.content, 'html.parser')
    moves = soup.find_all('li')
    print(moves)


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
        move_obj = Move(name, 10, 10, level_learned)
        moveset.append(move_obj)
        move_obj.print_move()
    return moveset


def get_stats():
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
        print(
            f"{name} - hp: {hp} - atk: {atk} - def: {de} - spd: {spd} - spatk: {spatk}")
        moveset = get_moveset(name)

        if name == 'Mew':
            break


get_stats()
