from typing import List


class MaxConsecutiveOnes:

    def find_max_consecutive_ones(self, nums: List[int]) -> int:
        result = counter = 0
        for num in nums:
            if num == 0:
                result = max(result, counter)
                counter = 0
            else:
                counter += 1
        return max(result, counter)
