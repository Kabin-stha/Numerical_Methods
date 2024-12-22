#include<stdio.h>
#include<math.h>

#define f(x) 2*exp(x)

int main() {
    float h, x, d;

    printf("Enter the value at which derivative is required\n ");
    scanf("%f", &x);

    printf("Enter increment h: ");
    scanf("%f", &h);

    d = (f(x + h) - f(x)) / h;

    // Print the result
    printf("Value of Derivative = %f\n", d);

    return 0;
}
