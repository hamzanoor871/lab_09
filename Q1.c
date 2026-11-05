#include <stdio.h>

float calculateItemTotal(float price, int quantity);
float calculateSubtotal(float total1, float total2);
float calculateDiscount(float subtotal);
float calculateFinalBill(float subtotal, float discount);
int findExpensiveItem(float price1, float price2);

int main()
{
    float price1, price2;
    int quantity1, quantity2;

    float total1, total2, subtotal, discount, finalBill;
    int expensiveItem;

    printf("Enter price of item 1: ");
    scanf("%f", &price1);

    printf("Enter quantity of item 1: ");
    scanf("%d", &quantity1);

    printf("Enter price of item 2: ");
    scanf("%f", &price2);

    printf("Enter quantity of item 2: ");
    scanf("%d", &quantity2);

    if (price1 < 0 || price2 < 0 || quantity1 < 0 || quantity2 < 0)
    {
        printf("Invalid input! Price and quantity cannot be negative.\n");
        return 0;
    }

    total1 = calculateItemTotal(price1, quantity1);
    total2 = calculateItemTotal(price2, quantity2);

    subtotal = calculateSubtotal(total1, total2);
    discount = calculateDiscount(subtotal);
    finalBill = calculateFinalBill(subtotal, discount);

    expensiveItem = findExpensiveItem(price1, price2);

    printf("\n========== CANTEEN RECEIPT ==========\n");
    printf("Item 1 Price:       Rs. %.2f\n", price1);
    printf("Item 1 Quantity:    %d\n", quantity1);
    printf("Item 1 Total:       Rs. %.2f\n", total1);

    printf("-------------------------------------\n");

    printf("Item 2 Price:       Rs. %.2f\n", price2);
    printf("Item 2 Quantity:    %d\n", quantity2);
    printf("Item 2 Total:       Rs. %.2f\n", total2);

    printf("-------------------------------------\n");
    printf("Subtotal:           Rs. %.2f\n", subtotal);
    printf("Discount:           Rs. %.2f\n", discount);
    printf("Final Bill:         Rs. %.2f\n", finalBill);

    printf("-------------------------------------\n");

    if (expensiveItem == 1)
        printf("Item 1 has the higher unit price.\n");
    else if (expensiveItem == 2)
        printf("Item 2 has the higher unit price.\n");
    else
        printf("Both items have equal unit prices.\n");

    printf("=====================================\n");

    return 0;
}

float calculateItemTotal(float price, int quantity)
{
    return price * quantity;
}

float calculateSubtotal(float total1, float total2)
{
    return total1 + total2;
}

float calculateDiscount(float subtotal)
{
    if (subtotal > 1000)
        return subtotal * 0.10;
    else
        return 0;
}

float calculateFinalBill(float subtotal, float discount)
{
    return subtotal - discount;
}

int findExpensiveItem(float price1, float price2)
{
    if (price1 > price2)
        return 1;
    else if (price2 > price1)
        return 2;
    else
        return 0;
}