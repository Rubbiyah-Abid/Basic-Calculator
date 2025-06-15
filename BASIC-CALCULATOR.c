#include <stdio.h>

#include <math.h>

// Function to check if the entered operator is valid
int isValidOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' ||
            op == '^' || op == '%' || op == 's' || op == '=');
}

int main() {
    // Variable declarations
    double num1 = 0, num2 = 0, result = 0;
    char op;
    int firstInput = 1; // Flag to check if it's the first number input

    // Displaying calculator header and instructions
    printf("======= LIVE CALCULATOR =======\n");
    printf("Instructions:\n");
    printf("Enter number -> operator -> number -> Enter\n");
    printf("Supported: + - * / ^ %% s (square root)\n");
    printf("'c' to clear, 'C' to turn off\n\n");

    while (1) {
        // Prompt for the first number
        if (firstInput) {
            printf("Enter number: ");
            if (scanf("%lf", &num1) != 1) {
                printf("Invalid input. Try again.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            firstInput = 0;
        }

        // Prompt for operator
        printf("Enter operator (+ - * / ^ %% s = c C): ");
        scanf(" %c", &op); // Space before %c to consume any leftover whitespace

        // Handle clear command
        if (op == 'c') {
            num1 = 0;
            firstInput = 1;
            printf("Calculator cleared.\n\n");
            continue;
        }

        // Handle off command
        if (op == 'C') {
            printf("Calculator turned off.\n");
            break;
        }

        // Validate operator
        if (!isValidOperator(op)) {
            printf("Invalid operator. Try again.\n");
            continue;
        }

        // Square root operation
        if (op == 's') {
            if (num1 < 0) {
                printf("Cannot calculate square root of a negative number.\n");
                continue;
            }
            result = sqrt(num1);
            printf("= %.2lf\n\n", result);
            num1 = result;
            continue;
        }

        // Equal sign without operation
        if (op == '=') {
            printf("Nothing to calculate.\n");
            continue;
        }

        // Prompt for the second number
        printf("Enter next number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("Invalid number. Try again.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        // Perform the selected operation
        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if (num2 == 0) {
                    printf("Cannot divide by zero.\n");
                    continue;
                }
                result = num1 / num2;
                break;
            case '^': result = pow(num1, num2); break;
            case '%': result = (num1 * num2) / 100; break; // Percentage calculation
        }

        // Display result and store it as the next input
        printf("= %.2lf\n\n", result);
        num1 = result;
    }

    return 0;
}
