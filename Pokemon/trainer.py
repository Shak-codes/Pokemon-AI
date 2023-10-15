from pokemon import Pokemon


class Trainer:
    def __init__(self, name: str):
        self.name: str = name

    def generate_team(self, names: list):
        self.team = []
        for name in names:
            self.team.append(Pokemon(name))

    def print_team(self):
        for pokemon in self.team:
            print(pokemon)


shak = Trainer('Shak')
shak.generate_team(['charizard', 'garchomp'])
shak.print_team()

aly = Trainer('Aly')
aly.generate_team(['vaporeon', 'gengar'])
aly.print_team()
