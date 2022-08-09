from typing import List


class RichestCustomerWealth:

    def maximum_wealth(self, accounts: List[List[int]]) -> int:
        result = 0
        for resources in accounts:
            current_customer_wealth = 0
            for resource in resources:
                current_customer_wealth += resource
            result = max(current_customer_wealth, result)
        return result
