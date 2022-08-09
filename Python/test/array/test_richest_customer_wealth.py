import unittest
from parameterized import parameterized

from src.array.richest_customer_wealth import RichestCustomerWealth


class RichestCustomerWealthTest(unittest.TestCase):

    @parameterized.expand([
        ([
             [1, 5],
             [7, 3],
             [3, 5]
         ], 10),
        ([
             [1, 2, 3],
             [3, 2, 1],
         ], 6),
        ([
             [2, 8, 7],
             [7, 1, 3],
             [1, 9, 5]
         ], 17)])
    def test_actual_return_against_expected(self, data, expected):
        actual = RichestCustomerWealth().maximum_wealth(data)
        self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
