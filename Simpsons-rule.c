#include <stdio.h>
#define f(x) (3 * (x) * (x) + 2 * (x) - 5) // Define the function f(x)

int main() {
    float h, x0, x1, x2, fx0, fx1, fx2, v;
    int n = 2; // Number of subintervals, must be 2 for Simpson's 1/3 Rule

    // Input the limits of integration
    printf("Enter Lower & Upper Limit:\n");
    scanf("%f %f", &x0, &x2);

    // Calculate step size
    h = (x2 - x0) / n;

    // Calculate intermediate points
    x1 = x0 + h;

    // Calculate function values
    fx0 = f(x0);
    fx1 = f(x1);
    fx2 = f(x2);

    // Apply Simpson's 1/3 Rule
    v = (h / 3) * (fx0 + 4 * fx1 + fx2);

    // Print the result
    printf("Value of Integration: %f\n", v);

    return 0;
}
