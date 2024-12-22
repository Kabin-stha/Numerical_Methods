#include <stdio.h>
#include <math.h>

int main() {
    int n, i, k, j, max_row;
    double pivot, term, sum = 0, a[10][10], b[10], x[10], temp;

    printf("Enter Dimension of System of equations\n");
    scanf("%d", &n);

    printf("Enter coefficients row-wise\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }

    printf("Enter RHS vector\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    // Forward Elimination with Partial Pivoting
    for (k = 0; k <= n - 2; k++) {
        // Partial Pivoting
        max_row = k;
        for (i = k + 1; i < n; i++) {
            if (fabs(a[i][k]) > fabs(a[max_row][k])) {
                max_row = i;
            }
        }

        // Swap rows if necessary
        if (max_row != k) {
            for (j = 0; j < n; j++) {
                temp = a[k][j];
                a[k][j] = a[max_row][j];
                a[max_row][j] = temp;
            }
            temp = b[k];
            b[k] = b[max_row];
            b[max_row] = temp;
        }

        pivot = a[k][k];
        if (fabs(pivot) < 0.000001) {
            printf("Method failed\n");
            return 1;
        }

        for (i = k + 1; i < n; i++) {
            term = a[i][k] / pivot;
            for (j = k; j < n; j++) {
                a[i][j] = a[i][j] - a[k][j] * term;
            }
            b[i] = b[i] - b[k] * term;
        }
    }

    // Back Substitution
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }

    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %lf\t", i + 1, x[i]);
    }

    return 0;
}
