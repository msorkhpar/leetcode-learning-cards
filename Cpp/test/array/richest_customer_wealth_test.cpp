#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "array/richest_customer_wealth.h"
#include "array/richest_customer_wealth.c"

struct RichestCustomerWealth_test_data {
    std::vector<std::vector<int>> customers;
    int result;
};

struct RichestCustomerWealthTest : public testing::TestWithParam<RichestCustomerWealth_test_data> {
};

INSTANTIATE_TEST_SUITE_P(
        RichestCustomerWealthTestCases,
        RichestCustomerWealthTest,
        testing::Values(
                RichestCustomerWealth_test_data{
                        {
                                {1, 5},
                                {7, 3},
                                {3, 5},
                        }, 10},
                RichestCustomerWealth_test_data{
                        {
                                {1, 2, 3},
                                {3, 2, 1}
                        }, 6},
                RichestCustomerWealth_test_data{
                        {
                                {2, 8, 7},
                                {7, 1, 3},
                                {1, 9, 5},
                        }, 17}
        )
);

TEST_P(RichestCustomerWealthTest, RichestCustomerWealthCppTestCase) {
    auto customers = GetParam().customers;
    auto expected = GetParam().result;

    auto actual = RichestCustomerWealth().MaximumWealth(customers);
    ASSERT_EQ(actual, expected);
}

TEST_P(RichestCustomerWealthTest, RichestCustomerWealthCTestCase) {
    auto customers = GetParam().customers;
    auto expected = GetParam().result;
    int customers_size = customers.size();
    int customers_col_size = customers[0].size();
    int **accounts;
    accounts = (int **) malloc(customers_size * sizeof accounts);

    int i = 0;
    int j;
    for (const auto &account: customers) // access by reference to avoid copying
    {
        j = 0;
        accounts[i] = (int *) malloc(customers_col_size * sizeof accounts[i]);
        for (const auto balance: account) {
            accounts[i][j++] = balance;
        }
        i++;
    }
    auto actual = maximumWealth(accounts, customers_size, &customers_col_size);
    ASSERT_EQ(actual, expected);
    free(accounts);
}