#include <stdio.h>

int main()
{
    int readings[7];
    int *ptr = readings;
    int *linkedMeter = NULL;

    int threshold;
    int total = 0;
    int highest;
    int day = 1;

    for (int i = 0; i < 7; i++)
    {
        printf("Enter reading for day %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("\n========== MEMORY INSPECTION ==========\n");

    for (int i = 0; i < 7; i++)
    {
        printf("Day %d: Reading = %d, Address = %p\n",
               i + 1, *(ptr + i), (void *)(ptr + i));
    }

    printf("\n========== ADDRESS DIFFERENCE ==========\n");

    for (int i = 0; i < 6; i++)
    {
        printf("Day %d to Day %d: %td bytes\n",
               i + 1, i + 2,
               (char *)(ptr + i + 1) - (char *)(ptr + i));
    }

    printf("\nEach address is %td bytes apart because an integer occupies %zu bytes in memory.\n",
           (char *)(ptr + 1) - (char *)ptr, sizeof(int));

    for (int i = 0; i < 7; i++)
    {
        total += *(ptr + i);
    }

    highest = *ptr;

    for (int i = 1; i < 7; i++)
    {
        if (*(ptr + i) > highest)
        {
            highest = *(ptr + i);
            day = i + 1;
        }
    }

    printf("\n========== WEEKLY ANALYSIS ==========\n");
    printf("Weekly Total: %d\n", total);
    printf("Highest Consumption: %d\n", highest);
    printf("Highest Consumption Day: %d\n", day);

    printf("\nEnter peak tariff threshold: ");
    scanf("%d", &threshold);

    for (int i = 0; i < 7; i++)
    {
        if (*(ptr + i) > threshold)
        {
            *(ptr + i) *= 2;
        }
    }

    printf("\n========== ADJUSTED READINGS ==========\n");

    for (int i = 0; i < 7; i++)
    {
        printf("Day %d: %d\n", i + 1, *(ptr + i));
    }

    printf("\n========== LINKED METER ==========\n");

    if (linkedMeter == NULL)
    {
        printf("Linked meter is not assigned.\n");
    }
    else
    {
        printf("Linked meter reading: %d\n", *linkedMeter);
    }

    linkedMeter = ptr + 2;

    if (linkedMeter == NULL)
    {
        printf("Linked meter is not assigned.\n");
    }
    else
    {
        printf("Linked meter is assigned to Day 3.\n");
        printf("Linked meter reading: %d\n", *linkedMeter);
        printf("Linked meter address: %p\n", (void *)linkedMeter);
    }

    return 0;
}