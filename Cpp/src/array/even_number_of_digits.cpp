#include "even_number_of_digits.h"

using namespace std;

bool has_even_number_of_digits(int num) {
    if (num < 2)
        return false;
    int number_of_digits = 0;
    while (num > 0) {
        number_of_digits++;
        num /= 10;
    }
    return number_of_digits % 2 == 0;
}

int EvenNumberOfDigits::FindNumbers(const vector<int> &nums) {
    int result = 0;
    for (int num: nums) {
        if (has_even_number_of_digits(num)) {
            result++;
        }
    }
    return result;
}
