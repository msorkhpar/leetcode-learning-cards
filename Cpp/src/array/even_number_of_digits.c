#include <stdbool.h>


bool has_even_number_of_digits_C(int num) {
    if (num < 2)
        return false;
    int number_of_digits = 0;
    while (num > 0) {
        number_of_digits++;
        num /= 10;
    }
    return number_of_digits % 2 == 0;
}

int find_numbers(int *nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        if (has_even_number_of_digits_C(nums[i])) {
            result++;
        }
    }
    return result;
}
