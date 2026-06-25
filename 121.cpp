/*
Problem: 121. Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Intuition:
To maximize profit, we need to buy the stock at the minimum price
seen so far and sell it on the current day.

At every index:
1. Assume we sell the stock today.
2. Calculate the profit using the minimum price encountered before today.
3. Update the maximum profit.
4. Update the minimum price seen so far.

Approach:
- Maintain two variables:
    minPrice  -> Minimum stock price seen so far.
    maxProfit -> Maximum profit obtained so far.

- Traverse the array once:
    profit = prices[i] - minPrice
    maxProfit = max(maxProfit, profit)
    minPrice = min(minPrice, prices[i])

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);

            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};