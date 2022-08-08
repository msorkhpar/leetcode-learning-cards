
#include "richest_customer_wealth.h"

using namespace std;

int RichestCustomerWealth::MaximumWealth(const vector<vector<int>> &accounts) {
    int result = 0;
    int current_customer_wealth = 0;
    for (const auto &account: accounts) // access by reference to avoid copying
    {
        current_customer_wealth = 0;
        for (const auto balance: account) {
            current_customer_wealth += balance;
        }
        if (current_customer_wealth > result) {
            result = current_customer_wealth;
        }
    }
    return result;
}