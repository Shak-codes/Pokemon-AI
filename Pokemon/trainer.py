from pokemon import Pokemon
import asyncio
from playsound import playsound
import climage


async def play_battle_music():
    playsound('music/battle.mp3', False)


class Trainer:
    def __init__(self, name: str):
        self.name: str = name

    def generate_team(self, names: list):
        self.team = []
        for name in names:
            self.team.append(Pokemon(name))

    def start_battle(self, opponent):
        battle_loop = asyncio.get_event_loop()
        asyncio.ensure_future(play_battle_music())
        asyncio.ensure_future(self.battle_loop(opponent))
        battle_loop.run_forever()

    async def battle_loop(self, opponent):
        user_team = self.team
        opponent_team = opponent.team
        usable_pokemon = [
            pokemon for pokemon in user_team if pokemon.current_hp > 0]
        opponent_usable_pokemon = [
            pokemon for pokemon in opponent_team if pokemon.current_hp > 0]
        user_switched_pokemon = True
        opponent_switched_pokemon = True
        current_pokemon = usable_pokemon[0]
        current_opponent_pokemon = opponent_usable_pokemon[0]
        while (len(usable_pokemon) > 0 and len(opponent_usable_pokemon) > 0):
            if (user_switched_pokemon):
                print(f"{self.name} sent out {current_pokemon.name}!")
                user_switched_pokemon = False
            if (opponent_switched_pokemon):
                print(f"{opponent.name} sent out {current_opponent_pokemon.name}!")
                opponent_switched_pokemon = False
            current_pokemon.print_move_damage(current_opponent_pokemon)
            current_opponent_pokemon.print_move_damage(current_pokemon)

    def print_team(self):
        for pokemon in self.team:
            print(pokemon)


shak = Trainer('Shak')
shak.generate_team(['charizard', 'garchomp'])
# shak.print_team()

aly = Trainer('Aly')
aly.generate_team(['vaporeon', 'gengar'])
# aly.print_team()

shak.start_battle(aly)
