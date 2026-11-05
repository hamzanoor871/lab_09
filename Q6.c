#include <stdio.h>

void printData(void *ptr, char type);

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int calculate(int a, int b, int (*operation)(int, int));

int main()
{
    int num = 25;
    float decimal = 15.75;
    char ch = 'A';

    int a, b, choice, result;

    void (*operations[4])(void);

    printf("========== GENERIC DATA PRINTER ==========\n");

    printData(&num, 'i');
    printData(&decimal, 'f');
    printData(&ch, 'c');

    int (*functions[4])(int, int) = {
        add, subtract, multiply, divide
    };

    printf("\n========== SMART CALCULATOR ==========\n");

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    printf("\n1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4)
    {
        printf("Invalid operation choice!\n");
        return 0;
    }

    if (choice == 4 && b == 0)
    {
        printf("Error! Division by zero is not allowed.\n");
        return 0;
    }

    result = calculate(a, b, functions[choice - 1]);

    printf("Result: %d\n", result);

    return 0;
}

void printData(void *ptr, char type)
{
    if (type == 'i')
        printf("Integer: %d\n", *(int *)ptr);

    else if (type == 'f')
        printf("Float: %.2f\n", *(float *)ptr);

    else if (type == 'c')
        printf("Character: %c\n", *(char *)ptr);
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int calculate(int a, int b, int (*operation)(int, int))
{
    return operation(a, b);
}