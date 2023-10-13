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
        name = response['name']
        move = {
            "type": response['type']['name'],
            "category": response['damage_class']['name'],
            "power": response['power'] if isinstance(response['power'], int) else 0,
            "accuracy": response['accuracy'] if isinstance(response['accuracy'], int) else 100
        }
        moves[name] = move
        print(
            f"Move {i}: {name} - Type: {move['type']} - Category: {move['category']} - Power: {move['power']} - Accuracy: {move['accuracy']}")
        time.sleep(0.3)
    with open('moves.json', 'w') as f:
        f.write(json.dumps(moves))


get_moves()
