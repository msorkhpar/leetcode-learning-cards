import unittest
from typing import List

from parameterized import parameterized

from src.general.fizz_buzz_calculator import FizzBuzzCalculator


class FizzBuzzCalculatorTest(unittest.TestCase):

    @parameterized.expand([
        (3, ["1", "2", "Fizz"]),
        (5, ["1", "2", "Fizz", "4", "Buzz"]),
        (15, ["1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"])
    ])
    def test_actual_return_against_expected(self, data: int, expected: List[str]):
        actual = FizzBuzzCalculator().fizz_buzz(data)
        self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
