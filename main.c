#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10  // Maximum matrix size

// Function to print the matrix
void printMatrix(float mat[SIZE][SIZE+1], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%8.3f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function for Gaussian elimination with solution checking
int gaussianElimination(float mat[SIZE][SIZE+1], int n) {
    for (int i = 0; i < n; i++) {
        // Find the maximum element in the column
        float maxElement = fabs(mat[i][i]);
        int maxRow = i;
        for (int k = i+1; k < n; k++) {
            if (fabs(mat[k][i]) > maxElement) {
                maxElement = fabs(mat[k][i]);
                maxRow = k;
            }
        }

        // Swap the rows
        for (int k = i; k <= n; k++) {
            float tmp = mat[maxRow][k];
            mat[maxRow][k] = mat[i][k];
            mat[i][k] = tmp;
        }

        // Check for a singular matrix (no unique solution)
        if (fabs(mat[i][i]) < 1e-7) {
            printf("No unique solution exists (singular or dependent system).\n");
            return 0;  // Return 0 to indicate failure
        }

        // Eliminate the rest of the rows
        for (int k = i+1; k < n; k++) {
            float factor = mat[k][i] / mat[i][i];
            for (int j = i; j <= n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }

        // Print the matrix after each elimination step
        printf("Matrix after step %d of elimination:\n", i + 1);
        printMatrix(mat, n);
    }

    return 1;  // Return 1 to indicate success
}

// Function for back substitution
void backSubstitution(float mat[SIZE][SIZE+1], float x[SIZE], int n) {
    for (int i = n-1; i >= 0; i--) {
        x[i] = mat[i][n] / mat[i][i];
        for (int j = i-1; j >= 0; j--) {
            mat[j][n] -= mat[j][i] * x[i];
        }
    }
}

// Main function
int main() {
    int n;
    float mat[SIZE][SIZE+1], x[SIZE];

    // Input matrix size
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    // Input the matrix coefficients (including the right-hand side)
    printf("Enter the coefficients of the matrix (including the right-hand side):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &mat[i][j]);
        }
    }

    // Print the initial matrix
    printf("Initial matrix:\n");
    printMatrix(mat, n);

    // Perform Gaussian elimination
    if (gaussianElimination(mat, n)) {
        // Perform back substitution if elimination was successful
        backSubstitution(mat, x, n);

        // Print the results
        printf("Solution to the system:\n");
        for (int i = 0; i < n; i++) {
            printf("x%d = %.3f\n", i+1, x[i]);
        }
    }

    return 0;
}
