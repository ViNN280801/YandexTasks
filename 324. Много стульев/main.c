#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void qSortAscending(int *arr, size_t size, size_t low, size_t high)
{
    size_t i = low, j = high;

    // Select pivot value
    int pivot = arr[(i + j) / 2], tmp = 0;

    while (i <= j && i < size && j < size)
    {
        while (arr[i] < pivot && i < size)
            i++;
        while (arr[j] > pivot && j < size)
            j--;
        if (i <= j && i < size && j < size)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    // Recursive call sorting to left side from pivot
    if (j > low && j < size)
        qSortAscending(arr, size, low, j);
    // Recursive call sorting to right side from pivot
    if (i < high && i < size)
        qSortAscending(arr, size, i, high);
}

void quickSortAscending(int *arr, size_t size) { qSortAscending(arr, size, 0, size - 1); }

void qSortDescending(int *arr, size_t size, size_t low, size_t high)
{
    size_t i = low, j = high;
    // Select pivot value
    int pivot = arr[(i + j) / 2], tmp = 0;

    while (i <= j && i < size && j < size)
    {
        while (arr[i] > pivot && i < size)
            i++;
        while (arr[j] < pivot && j < size)
            j--;
        if (i <= j && i < size && j < size)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    // Recursive call sorting to left side from pivot
    if (j > low && j < size)
        qSortDescending(arr, size, low, j);
    // Recursive call sorting to right side from pivot
    if (i < high && i < size)
        qSortDescending(arr, size, i, high);
}

void quickSortDescending(int *arr, size_t size) { qSortDescending(arr, size, 0, size - 1); }

int main()
{
    // Count of offers and count of potential customers
    int offers = 0, customers = 0;
    scanf("%d %d", &offers, &customers);

    // Prices at which sellers are willing to sell chairs
    int prices[offers];

    // Filling prices
    for (int i = 0; i < offers; i++)
        scanf("%d", &prices[i]);

    // Amounts that potential buyers are willing to give when buying a chair
    int amounts[customers];

    // Filling amounts
    for (int i = 0; i < customers; i++)
        scanf("%d", &amounts[i]);

    // 2 way: use "qsort()"
    quickSortAscending(prices, (size_t)offers);
    quickSortDescending(amounts, (size_t)customers);

    size_t result = 0, min = (offers > customers) ? customers : offers;
    for (size_t i = 0; i < min; i++)
    {
        int benefit = amounts[i] - prices[i];
        if (benefit > 0)
            result += benefit;
    }

    printf("%lu\n", result);

    return 0;
}
