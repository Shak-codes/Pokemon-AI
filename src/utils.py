import json
import pprint
import random
import math
from playsound import playsound

def calculate_stat(stat, base, iv, ev):
    if (stat == 'hp'):
        return math.floor(0.01*(2*base+iv+math.floor(0.25*ev))*50)+50 + 10
    else:
        return math.floor(0.01*(2*base+iv+math.floor(0.25*ev))*50) + 5
    
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

def generate_pokemon():
    data = json.load(open('data/pokemon.json'))
    count = data['count']
    pokemon_names = [*data.keys()]
    idx = random.randint(1, count)
    name = pokemon_names[idx]
    pokemon = data[name]
    moveset = generate_moveset(pokemon)
    evs, ivs, stats = generate_stats(pokemon)
    pokemon['evs'] = evs
    pokemon['ivs'] = ivs
    pokemon['stats'] = stats
    pokemon['moveset'] = moveset
    pokemon['level'] = random.randint(1, 100)
    return name, pokemon

def generate_team(team_size):
    team = []
    for i in range(team_size):
        name, pokemon = generate_pokemon()
        pokemon['name'] = name
        team.append(pokemon)
    return team

def calculate_damage(apokemon, dpokemon, move):
    power = move['power']
    if power > 0:
        level = apokemon['level']
        attack = apokemon['stats']['attack']
        defense = dpokemon['stats']['defense']
        rand = random.randint(85, 100)/100
        type = calculate_effectiveness(move['type'], dpokemon['types'])
        if move['category'] == 'special':
            attack = apokemon['stats']['special-attack']
            defense = dpokemon['stats']['special-defense']

        #print(f"Calculating damage for {apokemon['name']} using {move['name']} against {dpokemon['name']}")
        damage = math.floor((((2*level/5)+2)*power*attack/defense)/50 + 2) * rand * type
        #print(f"Damage: {damage}")
        damage = math.floor(damage)
        #print(f"Damage: {damage}")
        return damage
    #print(f"Calculating damage for {apokemon['name']} using {move['name']} against {dpokemon['name']}")
    #print("0 damage dealt!")
    return 0

def calculate_effectiveness(attack_type, defending_types):
    type_chart = json.load(open('data/types.json'))
    multiplier = 1
    for type in defending_types:
        multiplier *= type_chart[attack_type][type]
    return multiplier

def calculate_type_multiplier(pokemon, opponent):
    type_chart = json.load(open('data/types.json'))
    multiplier = 1
    pokemon_types = pokemon['types']
    print(pokemon_types)
    opponent_types = opponent['types']
    print(opponent_types)
    for utype in pokemon_types:
        for otype in opponent_types:
            multicand = type_chart[utype][otype] * (1/(type_chart[otype][utype] if type_chart[otype][utype] > 0 else 0))
            print(f"{utype} vs. {otype}: {type_chart[utype][otype]} and {otype} vs {utype}: {(1/type_chart[otype][utype])}")
            multiplier *= multicand
    return multiplier

def stat_differences(pokemon, opponent):
    pokemon_stats = pokemon['stats']
    opponent_stats = opponent['stats']
    phys_difference = pokemon_stats['attack'] - opponent_stats['defense']
    print(f"Physical difference: {phys_difference}")
    spec_difference = pokemon_stats['special-attack'] - opponent_stats['special-defense']
    print(f"Special difference: {spec_difference}")
    return phys_difference + spec_difference

def test():
    playsound('music/battle.mp3', False)
    pp = pprint.PrettyPrinter(depth=6, compact=False, sort_dicts=True)
    team1 = generate_team(1)
    team2 = generate_team(1)
    del team1[0]['moves']
    del team2[0]['moves']
    #pp.pprint(team1[0])
    #pp.pprint(team2[0])
    stat_diff = stat_differences(team1[0], team2[0])
    type_diff = calculate_type_multiplier(team1[0], team2[0])
    total_diff = stat_diff * type_diff
    if stat_diff < 0:
        total_diff = stat_diff * (1/type_diff)

    print(f"{team1[0]['name']} is this effective against {team2[0]['name']}: {total_diff}")
    #calculate_damage(team1[0], team2[0], team1[0]['moveset'][0])

test()