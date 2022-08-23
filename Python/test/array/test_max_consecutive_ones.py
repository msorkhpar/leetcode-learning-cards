import unittest
from parameterized import parameterized

from src.array.max_consecutive_ones import MaxConsecutiveOnes


class MaxConsecutiveOnesTest(unittest.TestCase):

    @parameterized.expand([
        ([1, 1, 0, 1, 1, 1], 3),
        ([1, 0, 1, 1, 0, 1], 2),
        ([1, 1, 1, 1, 1, 1], 6)
    ])
    def test_actual_return_against_expected(self, data, expected):
        actual = MaxConsecutiveOnes().find_max_consecutive_ones(data)
        self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
