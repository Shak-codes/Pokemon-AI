import unittest

from Move import Move


class TestInit(unittest.TestCase):
    def test_init(self):
        """
        Ensure that values are initialized properly
        """
        name = "Hydro Cannon"
        type = "Water"
        category = "Special"
        power = 150
        accuracy = 0.95
        result = Move(name, type, category, power, accuracy)

        self.assertEqual(result.name, "Hydro Cannon")
        self.assertEqual(result.type, "Water")
        self.assertEqual(result.category, "Special")
        self.assertEqual(result.power, 150)
        self.assertEqual(result.accuracy, 0.95)


if __name__ == '__main__':
    unittest.main()
