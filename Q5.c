#include <stdio.h>

void displayHall1(int (*ptr)[4], int rows);
void displayHall2(int *ptr[], int sizes[]);
int countVacantHall1(int (*ptr)[4], int rows);
int countVacantHall2(int *ptr[], int sizes[]);
void bookSeat(int *ptr[], int sizes[]);

int main()
{
    int hall1[3][4] = {
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 1}
    };

    int row1[3] = {1, 0, 1};
    int row2[5] = {0, 1, 0, 1, 0};
    int row3[7] = {1, 0, 0, 1, 0, 1, 0};

    int *hall2[3] = {row1, row2, row3};

    int sizes[3] = {3, 5, 7};

    printf("========== HALL 1 SEATING CHART ==========\n");

    displayHall1(hall1, 3);

    printf("Vacant Seats in Hall 1: %d\n", countVacantHall1(hall1, 3));

    printf("\n========== HALL 2 SEATING CHART ==========\n");

    displayHall2(hall2, sizes);

    printf("Vacant Seats in Hall 2: %d\n", countVacantHall2(hall2, sizes));

    bookSeat(hall2, sizes);

    printf("\n========== UPDATED HALL 2 CHART ==========\n");

    displayHall2(hall2, sizes);

    printf("Vacant Seats in Hall 2: %d\n", countVacantHall2(hall2, sizes));

    return 0;
}

void displayHall1(int (*ptr)[4], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        printf("Row %d: ", i + 1);

        for (int j = 0; j < 4; j++)
        {
            if (*(*(ptr + i) + j) == 1)
                printf("[B] ");
            else
                printf("[V] ");
        }

        printf("\n");
    }
}

int countVacantHall1(int (*ptr)[4], int rows)
{
    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (*(*(ptr + i) + j) == 0)
                count++;
        }
    }

    return count;
}

void displayHall2(int *ptr[], int sizes[])
{
    for (int i = 0; i < 3; i++)
    {
        printf("Row %d: ", i + 1);

        for (int j = 0; j < sizes[i]; j++)
        {
            if (*(*(ptr + i) + j) == 1)
                printf("[B] ");
            else
                printf("[V] ");
        }

        printf("\n");
    }
}

int countVacantHall2(int *ptr[], int sizes[])
{
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            if (*(*(ptr + i) + j) == 0)
                count++;
        }
    }

    return count;
}

void bookSeat(int *ptr[], int sizes[])
{
    int row, seat;

    printf("\n========== BOOK A SEAT ==========\n");

    printf("Enter row number (1-3): ");
    scanf("%d", &row);

    if (row < 1 || row > 3)
    {
        printf("Invalid row! This row does not exist.\n");
        return;
    }

    printf("Enter seat number (1-%d): ", sizes[row - 1]);
    scanf("%d", &seat);

    if (seat < 1 || seat > sizes[row - 1])
    {
        printf("Invalid seat! This seat does not exist in this row.\n");
        return;
    }

    if (*(*(ptr + row - 1) + seat - 1) == 1)
    {
        printf("Booking failed! This seat is already booked.\n");
        return;
    }

    *(*(ptr + row - 1) + seat - 1) = 1;

    printf("Seat booked successfully!\n");
}