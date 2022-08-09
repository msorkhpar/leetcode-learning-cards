
#include <malloc.h>

int maximumWealth(int **accounts, int accountsSize, int *accountsColSize) {
    int result = 0;
    int current_customer_wealth;
    for (int i = 0; i < accountsSize; i++) // access by reference to avoid copying
    {
        current_customer_wealth = 0;
        for (int j = 0; j < *accountsColSize; j++) {
            current_customer_wealth += accounts[i][j];
        }
        if (current_customer_wealth > result) {
            result = current_customer_wealth;
        }
    }
    return result;
}