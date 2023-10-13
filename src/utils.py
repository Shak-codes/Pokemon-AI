import json
import pprint
import random
import math


def generate_pokemon():
    pokemon_data = json.load(open('data/pokemon.json'))
    length = pokemon_data['count']
    idx = random.randint(1, length)
    pokemon_list = [*pokemon_data.keys()]
    name = pokemon_list[idx]
    pokemon = pokemon_data[name]
    moveset = generate_moveset(pokemon)
    evs, ivs, stats = generate_stats(pokemon)
    pokemon['evs'] = evs
    pokemon['ivs'] = ivs
    pokemon['stats'] = stats
    pokemon['moveset'] = moveset
    pokemon['level'] = 50
    return name, pokemon


def generate_moveset(pokemon):
    move_data = json.load(open('data/moves.json'))
    movepool = pokemon['moves']
    length = len(movepool)
    moveset = []
    indices = []
    for i in range(4):
        while True:
            # Make sure length > 1
            idx = random.randint(0, length-1)
            if (idx not in indices):
                move = move_data[movepool[idx]]
                move['name'] = movepool[idx]
                moveset.append(move)
                indices.append(idx)
                break
    return moveset


def generate_team(team_size):
    team = []
    for i in range(team_size):
        name, pokemon = generate_pokemon()
        pokemon['name'] = name
        team.append(pokemon)
    return team


def calculate_stat(stat, base, iv, ev):
    if (stat == 'hp'):
        return math.floor(0.01*(2*base+iv+math.floor(0.25*ev))*50)+50 + 10
    else:
        return math.floor(0.01*(2*base+iv+math.floor(0.25*ev))*50) + 5


def generate_stats(pokemon):
    stat_names = ["hp", "attack", "defense",
                  "special-attack", "special-defense", "speed"]
    remaining_evs = 510
    evs = {}
    ivs = {}
    stats = {}
    for stat in stat_names:
        ev = 0
        if remaining_evs > 252:
            ev = random.randint(0, 252)
        elif remaining_evs > 0:
            ev = random.randint(0, remaining_evs)
        iv = random.randint(0, 31)
        base = pokemon['base-stats'][stat]
        stats[stat] = calculate_stat(stat, base, iv, ev)
        remaining_evs -= ev
        evs[stat] = ev
        ivs[stat] = iv
    return evs, ivs, stats

def calculate_damage(apokemon, dpokemon, move):
    level = apokemon['level']
    power = move['power']
    attack = apokemon['stats']['attack']
    defense = dpokemon['stats']['defense']
    rand = random.randint(85, 100)/100
    if move['category'] == 'special':
        attack = apokemon['stats']['special-attack']
        defense = dpokemon['stats']['special-defense']

    print(f"Calculating damage for {apokemon['name']} using {move['name']} against {dpokemon['name']}")
    damage = math.floor((((2*level/5)+2)*power*attack/defense)/50 + 2) * rand
    print(f"Damage: {damage}")
    damage = math.floor(damage)
    print(f"Damage: {damage}")
    return damage

def test():
    pp = pprint.PrettyPrinter(depth=6, compact=False, sort_dicts=True)
    team1 = generate_team(1)
    team2 = generate_team(1)
    del team1[0]['moves']
    del team2[0]['moves']
    pp.pprint(team1[0])
    pp.pprint(team2[0])
    calculate_damage(team1[0], team2[0], team1[0]['moveset'][0])


test()
