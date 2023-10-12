import time
import requests
import json


def get_moves():
    move_count = 905
    moves = {}
    endpoint = "http://pokeapi.co/api/v2/move/"
    for i in range(1, move_count):
        response = requests.get(endpoint+str(i))
        response = response.json()
        if (isinstance(response['power'], int) and isinstance(response['accuracy'], int)):
            name = response['name']
            move = {
                "type": response['type']['name'],
                "category": response['damage_class']['name'],
                "power": response['power'],
                "accuracy": response['accuracy']/100
            }
            moves[name] = move
            print(
                f"Move {i}: {name} - Type: {move['type']} - Category: {move['category']} - Power: {move['power']} - Accuracy: {move['accuracy']}")
            time.sleep(0.3)
        else:
            print(f"Move {i} skipped")
    with open('moves.json', 'w') as f:
        f.write(json.dumps(moves))


get_moves()
