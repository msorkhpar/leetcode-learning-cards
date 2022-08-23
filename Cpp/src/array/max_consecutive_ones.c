#include <stdio.h>

int find_max_consecutive_ones(int *nums, int numsSize) {
    int result = 0;
    int counter = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            counter++;
        } else {
            result = result > counter ? result : counter;
            counter = 0;
        }
    }
    result = result > counter ? result : counter;

    return result;
}
