#include<stdio.h>
#include<math.h>

// Define the function for which the derivative is to be calculated
#define f(x) (sin(x) + 1)

int main() {
    float angle, h, x, d;

    // Prompt the user for input
    printf("Enter Angle in Degrees: ");
    scanf("%f", &angle);

    printf("Enter increment h: ");
    scanf("%f", &h);

    // Convert angle to radians
    x = M_PI / 180 * angle;

    // Calculate the derivative using the forward difference formula
    d = (f(x + h) - f(x)) / h;

    // Print the result
    printf("Value of Derivative = %f\n", d);

    return 0;
}
