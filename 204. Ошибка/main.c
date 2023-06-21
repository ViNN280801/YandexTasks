#include <stdio.h> // For standard input/output

int main()
{
    // Count of servers (1 <= n <= 100)
    int n = 0;
    scanf("%d", &n);

    // Reserving space for 'n' servers
    int probabilities[n];

    // Probability that error occurs on accordingly server
    int totalProbability = 0;

    // Filling 'n' probabilities
    for (int i = 0; i < n; i++)
    {
        // 'a' - the probability that the request will go to the i-th server in percents (0 <= a <= 100)
        // 'b' - the probability that an error will occur on the i-th server in percents (0 <= b <= 100)
        // It's guaranteed that sum of all 'a_i' = 100%
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);

        // Adding probability of an error to the vector of probabilities
        probabilities[i] = a * b;

        // Calculating total probability as sum of elements all probabilities
        totalProbability += probabilities[i];
    }

    // Outputting result
    for (int i = 0; i < n; i++)
        printf("%.12lf\n", (double)probabilities[i] / (double)totalProbability);

    return 0;
}
