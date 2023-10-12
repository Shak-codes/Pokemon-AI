import time
import requests
import json

def get_pokemon():
    endpoint = "https://beta.pokeapi.co/graphql/v1beta"
    query = """
    {
        pokemon_v2_pokemon(order_by: {id: asc}) {
            name
            pokemon_v2_pokemontypes {
            pokemon_v2_type {
                name
            }
            }
            pokemon_v2_pokemonmoves(limit: 30) {
            pokemon_v2_move {
                name
            }
            }
            pokemon_v2_pokemonstats {
            pokemon_v2_stat{name}
            base_stat
            }
        }
    }
    """
    response = requests.post(endpoint, json={"query": query})
    response = response.json()

    pokemon = {}

    for pkmn in response['data']['pokemon_v2_pokemon']:
        name = pkmn['name']
        type_list = pkmn['pokemon_v2_pokemontypes']
        move_list = pkmn['pokemon_v2_pokemonmoves']
        stat_list = pkmn['pokemon_v2_pokemonstats']
        data = {
            "types": [],
            "moves": [],
            "stats": {}
        }

        for type in type_list:
            data['types'].append(type['pokemon_v2_type']['name'])
        
        for move in move_list:
            data['moves'].append(move['pokemon_v2_move']['name'])

        for stat in stat_list:
            data['stats'][stat['pokemon_v2_stat']['name']] = stat['base_stat']

        pokemon[name] = data

        #print(f"Pokemon: {name}\nTypes: {data['types']}\nMoves: {data['moves']}\nStats: {data['stats']}")
    with open('pokemon.json', 'w') as f: 
        f.write(json.dumps(pokemon))

get_pokemon()