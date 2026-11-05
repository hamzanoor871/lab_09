#include <stdio.h>

void swapWrong(int a, int b);
void swapCorrect(int *a, int *b);
void analyzeOccupancy(int arr[], int size, int *total, int *highest, int *lowest);

int main()
{
    int wardA = 25, wardB = 40;
    int x = 15, y = 30;

    int occupancy[7] = {20, 35, 25, 40, 30, 45, 15};

    int total, highest, lowest;

    printf("========== BEFORE SWAPPING ==========\n");

    printf("Ward A: %d, Address: %p\n", wardA, (void *)&wardA);
    printf("Ward B: %d, Address: %p\n", wardB, (void *)&wardB);

    swapCorrect(&wardA, &wardB);

    printf("\n========== AFTER CORRECT SWAPPING ==========\n");

    printf("Ward A: %d, Address: %p\n", wardA, (void *)&wardA);
    printf("Ward B: %d, Address: %p\n", wardB, (void *)&wardB);

    printf("\n========== PASS BY VALUE ==========\n");

    printf("Before function: x = %d, y = %d\n", x, y);
    printf("Main addresses: x = %p, y = %p\n", (void *)&x, (void *)&y);

    swapWrong(x, y);

    printf("After function: x = %d, y = %d\n", x, y);

    printf("\n========== WEEKLY OCCUPANCY ==========\n");

    analyzeOccupancy(occupancy, 7, &total, &highest, &lowest);

    printf("\n========== RESULTS ==========\n");

    printf("Total Occupancy: %d\n", total);
    printf("Highest Occupancy: %d\n", highest);
    printf("Lowest Occupancy: %d\n", lowest);

    return 0;
}

void swapWrong(int a, int b)
{
    int temp;

    printf("Function addresses: a = %p, b = %p\n", (void *)&a, (void *)&b);

    temp = a;
    a = b;
    b = temp;

    printf("Inside function: a = %d, b = %d\n", a, b);
}

void swapCorrect(int *a, int *b)
{
    int temp;

    printf("\nFunction addresses: a = %p, b = %p\n", (void *)a, (void *)b);

    temp = *a;
    *a = *b;
    *b = temp;
}

void analyzeOccupancy(int arr[], int size, int *total, int *highest, int *lowest)
{
    *total = 0;
    *highest = arr[0];
    *lowest = arr[0];

    printf("Function array address: %p\n", (void *)arr);
    printf("First element address: %p\n", (void *)&arr[0]);
    printf("Total variable address: %p\n", (void *)total);
    printf("Highest variable address: %p\n", (void *)highest);
    printf("Lowest variable address: %p\n", (void *)lowest);

    for (int i = 0; i < size; i++)
    {
        *total += arr[i];

        if (arr[i] > *highest)
        {
            *highest = arr[i];
        }

        if (arr[i] < *lowest)
        {
            *lowest = arr[i];
        }
    }
}