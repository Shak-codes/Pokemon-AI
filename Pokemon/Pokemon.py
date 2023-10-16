import json
import random
import pprint
import math
from move import Move


def calculate_stat(level, stat, base, iv, ev):
    if (stat == 'hp'):
        return math.floor(0.01*(2*base+iv+math.floor(0.25*ev))*level)+level + 10
    else:
        return math.floor(0.01*(2*base+iv+math.floor(0.25*ev))*level) + 5


class Pokemon:
    pp = pprint.PrettyPrinter(depth=10, compact=False, sort_dicts=True)
    stat_names = ["hp", "attack", "defense",
                  "special-attack", "special-defense", "speed"]
    pokemon_list = json.load(open('data/pokemon.json'))

    def __init__(self, name: str):
        self.data = Pokemon.pokemon_list[name]
        self.name = name
        self.types = self.data['types']
        self.base_stats = self.data['base-stats']
        self.level = random.randint(1, 100)
        self.generate_stats()
        self.generate_moveset()

    def __str__(self):
        return (f"{self.name.capitalize()}\n"
                f"Level: {self.level}\n"
                f"Base stats: HP - {self.base_stats['hp']} | Attack - {self.base_stats['attack']} | Defense - {self.base_stats['defense']} | Sp. Atk - {self.base_stats['special-attack']} | Sp. Def - {self.base_stats['special-defense']} | Speed - {self.base_stats['speed']}\n"
                f"Stats: HP - {self.stats['hp']} | Attack - {self.stats['attack']} | Defense - {self.stats['defense']} | Sp. Atk - {self.stats['special-attack']} | Sp. Def - {self.stats['special-defense']} | Speed - {self.stats['speed']}\n"
                f"Moveset:\n"
                f"{self.print_moveset()}")

    def generate_stats(self):
        remaining_evs = 510
        self.evs = {}
        self.ivs = {}
        self.stats = {}
        for stat in self.stat_names:
            ev = 0
            if remaining_evs > 252:
                ev = random.randint(0, 252)
            elif remaining_evs > 0:
                ev = random.randint(0, remaining_evs)
            iv = ev // (252/31)
            base = self.base_stats[stat]
            self.stats[stat] = calculate_stat(self.level, stat, base, iv, ev)
            remaining_evs -= ev
            self.evs[stat] = ev
            self.ivs[stat] = iv
        self.current_hp = self.stats['hp']

    def generate_moveset(self):
        movepool: list = self.data['moves']
        moveset = []
        while len(moveset) < 4:
            move_name = random.choice(movepool)
            move = Move(move_name)
            moveset.append(move)
            movepool.remove(move_name)
        self.moveset = moveset

    def calculate_damage(self, opponent, move):
        print(f"{self.name.capitalize()} used {move.name} against {opponent.name}!")
        if move.power > 0:
            level = self.level
            attack = self.stats['attack'] if move.category == 'physical' else self.stats['special-attack']
            defense = opponent.stats['defense'] if move.category == 'physical' else opponent.stats['special-defense']
            rand = random.randint(85, 100)/100
            type = move.move_effectiveness(self.types, opponent.types)
            damage = math.floor(
                (((2*level/5)+2)*move.power*attack/defense)/50 + 2) * rand * type
            damage = math.floor(damage)
            return damage
        return 0

    def print_info(self):
        print(f"Level {self.level} {self.name.capitalize()}")

    def print_stats(self):
        print("Stats:")
        self.pp.pprint(self.stats)

    def print_moveset(self):
        moveset = ""
        for move in self.moveset:
            moveset += move.get_move_data()
            moveset += "\n"
        return moveset

    def print_move_damage(self, opponent):
        move = int(input("Which move would you like to use? "))
        print(
            f"It did {self.calculate_damage(opponent, self.moveset[move])} damage!")
