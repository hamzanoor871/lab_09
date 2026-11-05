#include <stdio.h>

int calculateTotal(int marks[], int size);
float calculateAverage(int total, int size);
int findHighest(int marks[], int size);
int findLowest(int marks[], int size);
int countPass(int marks[], int size, int threshold);
int countTopScorers(int marks[], int size);
void applyBonus(int marks[], int size, int bonus);
void displayReport(int marks[], int size, int threshold);

int main()
{
    int marks[10];
    int threshold, bonus;

    for (int i = 0; i < 10; i++)
    {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);

        while (marks[i] < 0 || marks[i] > 100)
        {
            printf("Invalid marks! Enter marks between 0 and 100: ");
            scanf("%d", &marks[i]);
        }
    }

    printf("\nEnter passing threshold: ");
    scanf("%d", &threshold);

    while (threshold < 0 || threshold > 100)
    {
        printf("Invalid threshold! Enter between 0 and 100: ");
        scanf("%d", &threshold);
    }

    printf("\n========== ORIGINAL MARKS REPORT ==========\n");
    displayReport(marks, 10, threshold);

    printf("\nEnter bonus marks: ");
    scanf("%d", &bonus);

    while (bonus < 0)
    {
        printf("Invalid bonus! Enter a non-negative value: ");
        scanf("%d", &bonus);
    }

    applyBonus(marks, 10, bonus);

    printf("\n========== MODERATED MARKS REPORT ==========\n");
    displayReport(marks, 10, threshold);

    return 0;
}

int calculateTotal(int marks[], int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        total += marks[i];
    }

    return total;
}

float calculateAverage(int total, int size)
{
    return (float)total / size;
}

int findHighest(int marks[], int size)
{
    int highest = marks[0];

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}

int findLowest(int marks[], int size)
{
    int lowest = marks[0];

    for (int i = 1; i < size; i++)
    {
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}

int countPass(int marks[], int size, int threshold)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (marks[i] >= threshold)
        {
            count++;
        }
    }

    return count;
}

int countTopScorers(int marks[], int size)
{
    int highest = findHighest(marks, size);
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (marks[i] == highest)
        {
            count++;
        }
    }

    return count;
}

void applyBonus(int marks[], int size, int bonus)
{
    for (int i = 0; i < size; i++)
    {
        marks[i] += bonus;

        if (marks[i] > 100)
        {
            marks[i] = 100;
        }
    }
}

void displayReport(int marks[], int size, int threshold)
{
    int total = calculateTotal(marks, size);
    float average = calculateAverage(total, size);
    int highest = findHighest(marks, size);
    int lowest = findLowest(marks, size);
    int passed = countPass(marks, size, threshold);
    int topScorers = countTopScorers(marks, size);

    printf("\nClass Total: %d\n", total);
    printf("Class Average: %.2f\n", average);
    printf("Highest Marks: %d\n", highest);
    printf("Lowest Marks: %d\n", lowest);
    printf("Students Passed: %d\n", passed);
    printf("Students Sharing Top Marks: %d\n", topScorers);
}