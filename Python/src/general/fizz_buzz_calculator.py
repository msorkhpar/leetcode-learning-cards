from typing import List


class FizzBuzzCalculator:

    def fizz_buzz(self, data: int) -> List[str]:
        result = []
        for i in range(1, data+1):
            if i % 3 == 0:
                if i % 5 == 0:
                    result.append("FizzBuzz")
                else:
                    result.append("Fizz")
            elif i % 5 == 0:
                result.append("Buzz")
            else:
                result.append(str(i))
        return result
