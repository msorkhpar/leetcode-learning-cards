import unittest
from parameterized import parameterized

from src.array.even_number_of_digits import EvenNumberOfDigits


class EvenNumberOfDigitsTest(unittest.TestCase):

    @parameterized.expand([
        ([0], 0),
        ([1771], 1),
        ([1772], 1),
        ([12, 345, 2, 6, 7896], 2),
        ([555, 901, 482, 1771], 1)
    ])
    def test_actual_return_against_expected(self, data, expected):
        actual = EvenNumberOfDigits().find_numbers(data)
        self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
