#include<stdio.h>

int main() {
    int n, i;
    float a = 0, b = 0, x[100], y[100], sx = 0, sy = 0, sxy = 0, sx2 = 0;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("At least two points are required to fit a line.\n");
        return 1;
    }

    if (n > 100) {
        printf("Number of points exceeds the limit (100).\n");
        return 1;
    }

    printf("Enter the values of x and fx (separated by a space):\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    // Calculate summations
    for (i = 0; i < n; i++) {
        sx += x[i];
        sy += y[i];
        sxy += x[i] * y[i];
        sx2 += x[i] * x[i];
    }

    // Validate denominator for slope calculation
    float denominator = (n * sx2) - (sx * sx);
    if (denominator == 0) {
        printf("Cannot fit a line to these points (denominator is zero).\n");
        return 1;
    }

    // Calculate coefficients
    b = ((n * sxy) - (sx * sy)) / denominator;
    a = (sy / n) - (b * sx / n);

    printf("Fitted line is: y = %.2f + %.2f * x\n", a, b);

    return 0;
}
