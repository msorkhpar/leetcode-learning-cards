#include <malloc.h>
#include <string.h>

char **fizz_buzz(int input, int *return_size) {
    *return_size = input;
    char **result = (char **) malloc(input * sizeof(char *));
    for (int number = 1, index = 0; number <= input; number++, index++) {
        result[index] = (char *) malloc((strlen("FizzBuzz") + 1) * sizeof(char));
        if (number % 3 == 0) {
            if (number % 5 == 0) {
                result[index] = "FizzBuzz";
            } else {
                result[index] = "Fizz";
            }
        } else if (number % 5 == 0) {
            result[index] = "Buzz";
        } else {
            sprintf(result[index], "%d", number);
        }
    }
    return result;
}
