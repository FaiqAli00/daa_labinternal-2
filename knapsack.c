#include <stdio.h>

int max(int, int);
int knapsackbrute(int, int[], int[], int);

int main()
{
    int profit[] = {42, 12, 40, 25};
    int weight[] = {7, 3, 4, 5};
    int m = 10, i;
    int n = sizeof(profit) / sizeof(profit[0]);

    printf("KNAPSACK USING BRUTE FORCE\n\n");
    printf("Profits of objects are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", profit[i]);

    printf("\n\nWeights of objects are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", weight[i]);

    printf("\n\nOptimal Solution is:");
    printf("%d", knapsackbrute(m, weight, profit, n));

    return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsackbrute(int m, int w[], int p[], int n)
{
    if (n == 0 || m == 0)
        return 0;

    if (w[n - 1] > m)
        return knapsackbrute(m, w, p, n - 1);
    else
        return max(p[n - 1] + knapsackbrute(m - w[n - 1], w, p, n - 1), knapsackbrute(m, w, p, n - 1));
}
