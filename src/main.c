#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    int choice = 0;

    do
    {
        system("cls");
        printf(
            "==============================\n"
            "This is a calculator app.\n"
            "What do you want to do?\n"
            "1. Addition\n"
            "2. Subtraction\n"
            "3. Multiplication\n"
            "4. Division\n"
            "5. Exit\n"
            "------------------------------\n");

        choice = 0;
        scanf("%d", &choice);
        printf("You chose %d\n", choice);

        switch (choice)
        {
        case 1:
            printf("You chose addition\n");
            addition();
            break;
        case 2:
            printf("You chose subtraction\n");
            subtraction();
            break;
        case 3:
            printf("You chose multiplication\n");
            break;
        case 4:
            printf("You chose division\n");
            break;
        case 5:
            printf("You chose exit\n");
            break;
        default:
            break;
        }

        printf("Press any key to continue...\n");
        getchar();

    } while (choice != 5);

    return 0;
}

/**
 * Prompts the user for two numbers, calculates their sum, and prints the result.
 *
 * This function is an implementation detail of the calculator application. It is
 * called from the main menu when the user selects the "Addition" option.
 *
 * @return 0 on successful completion.
 */
int addition()
{
    printf("What is the first number?\n");
    int num1 = 0;
    scanf("%d", &num1);
    printf("What is the second number?\n");
    int num2 = 0;
    scanf("%d", &num2);
    printf("The sum of %d and %d is %d\n", num1, num2, num1 + num2);

    return 0;
}

/**
 * Prompts the user for two numbers, calculates their difference, and prints the result.
 *
 * This function is an implementation detail of the calculator application. It is
 * called from the main menu when the user selects the "Subtraction" option.
 *
 * @return 0 on successful completion.
 */
int subtraction()
{
    printf("What is the first number?\n");
    int num1 = 0;
    scanf("%d", &num1);
    printf("What is the second number?\n");
    int num2 = 0;
    scanf("%d", &num2);
    printf("The difference of %d and %d is %d\n", num1, num2, num1 - num2);

    return 0;
}