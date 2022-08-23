#include <iostream>
#include "max_consecutive_ones.h"

using namespace std;

int MaxConsecutiveOnes::FindMaxConsecutiveOnes(const vector<int> &nums) {
    int result = 0;
    int counter = 0;
    for (const auto &num: nums) {
        if (num != 0) {
            counter++;
        } else {
            result = max(counter, result);
            counter =0;
        }
    }
    result = max(counter, result);
    return result;
}
