#include <iostream>
#include <vector>
#include <algorithm>

#include "sum_of_1d_array.h"


using namespace std;

vector<int> SumOf1DArray::RunningSum(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}