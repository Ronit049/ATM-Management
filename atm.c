#include <stdio.h>
#include <stdlib.h>

int main() {
    int pin = 1234;         // Default ATM PIN
    int enteredPin, choice;
    float balance = 1000.0; // Initial balance
    float withdraw, deposit;

    // Welcome message
    printf("Welcome to the ATM Simulation!\n");

    // PIN verification
    printf("Please enter your PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("Incorrect PIN. Access Denied.\n");
        return 0; // Exit if PIN is incorrect
    }

    // Main menu
    while (1) {
        printf("\nATM Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your current balance is: $%.2f\n", balance);
                break;

            case 2:
                printf("Enter the amount to deposit: $");
                scanf("%f", &deposit);
                balance += deposit;
                printf("You have successfully deposited $%.2f\n", deposit);
                break;

            case 3:
                printf("Enter the amount to withdraw: $");
                scanf("%f", &withdraw);
                if (withdraw > balance) {
                    printf("Insufficient funds. Your current balance is: $%.2f\n", balance);
                } else {
                    balance -= withdraw;
                    printf("You have successfully withdrawn $%.2f\n", withdraw);
                }
                break;

            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
