// Write a code using your suitable language(C,C++,Java,any other) for Coin Change Problem

#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int coinChange(int coins[], int m, int V)
{
    int dp[V + 1];
    dp[0] = 0;

    for (int i = 1; i <= V; i++)
    {
        dp[i] = INT_MAX;
    }
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (coins[j] <= i)
            {
                int sub = dp[i - coins[j]];
                if (sub != INT_MAX)
                {
                    dp[i] = min(dp[i], sub + 1);
                }
            }
        }
    }

    if (dp[V] == INT_MAX)
    {
        return -1;
    }
    return dp[V];
}

int main()
{
    int coins[] = {1, 3, 5};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 8;

    printf("Minimun coins need: %d\n", coinChange(coins, m, V));

    return 0;
}