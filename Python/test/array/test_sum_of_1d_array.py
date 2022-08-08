import unittest
from parameterized import parameterized, parameterized_class

from src.array.sum_of_1d_array import SumOf1DArray


class SumOf1DArrayTest(unittest.TestCase):

    @parameterized.expand([
        ([1, 1, 1, 1, 1], [1, 2, 3, 4, 5]),
        ([1, 2, 3, 4], [1, 3, 6, 10]),
        ([3, 1, 2, 10, 1], [3, 4, 6, 16, 17])
    ])
    def test_actual_return_against_expected(self, numbers, expected):
        actual = SumOf1DArray().running_sum(numbers)
        self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
