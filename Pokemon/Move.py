import json


class Move:
    move_list = json.load(open('data/moves.json'))
    type_chart = json.load(open('data/types.json'))

    def __init__(self, name: str):
        self.name = name
        move = self.move_list[name]
        self.power = move['power']
        self.category = move['category']
        self.type = move['type']
        self.accuracy = move['accuracy']

    def get_move_data(self):
        return f"       - {self.name.capitalize()}: Power - {self.power} | Category - {self.category.capitalize()} | Type - {self.type.capitalize()} | Accuracy - {self.accuracy}"

    def move_effectiveness(self, user_types: list, opponent_types: list):
        multiplier = 1
        for type in opponent_types:
            multiplier *= self.type_chart[self.type][type]
        if self.type in user_types:
            multiplier *= 1.5
        return multiplier
