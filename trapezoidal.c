#include <stdio.h>
#define f(x) ((x) + 2) // Define the function f(x)

int main() {
    float h, x0, x1, fx0, fx1, v;

    // Input the limits of integration
    printf("Enter Lower & Upper Limit:\n");
    scanf("%f %f", &x0, &x1);

    // Calculate step size
    h = x1 - x0;

    // Calculate function values at the limits
    fx0 = f(x0);
    fx1 = f(x1);

    // Apply Trapezoidal Rule
    v = (h / 2) * (fx0 + fx1);

    // Print the result
    printf("Value of Integration: %f\n", v);

    return 0;
}
