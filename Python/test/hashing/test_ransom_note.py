import unittest
from parameterized import parameterized

from src.hashing.ransom_note import RansomNote


class RansomNoteTest(unittest.TestCase):

    @parameterized.expand([
        ("a", "b", False),
        ("aa", "ab", False),
        ("aa", "aab", True),
    ])
    def test_actual_return_against_expected(self, ransom_note, magazine, expected):
        actual = RansomNote().can_construct(ransom_note, magazine)
        self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
