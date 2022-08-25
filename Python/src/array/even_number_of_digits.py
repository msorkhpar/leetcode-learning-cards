from typing import List


def has_even_number_of_digits(num: int) -> bool:
    if num < 2:
        return False
    number_of_digits = 0
    while num > 0:
        number_of_digits += 1
        num //= 10
    return number_of_digits % 2 == 0


class EvenNumberOfDigits:

    def find_numbers(self, nums: List[int]) -> int:
        result = 0
        for num in nums:
            if has_even_number_of_digits(num):
                result += 1
        return result
