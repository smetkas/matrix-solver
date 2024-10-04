# Gaussian Elimination Program

## Overview

This C program implements the Gaussian elimination method for solving systems of linear equations. It can handle a maximum of 10 unknowns and provides step-by-step output of the elimination process. The program includes checks for singular or dependent systems, notifying the user when a unique solution does not exist.

## Features

- Input the number of unknowns.
- Enter the coefficients of the matrix, including the right-hand side.
- Perform Gaussian elimination with detailed step-by-step output.
- Conduct back substitution to find the solution to the system of equations.
- Handle cases with no unique solution due to singular or dependent systems.

## Requirements

- A C compiler (e.g., GCC)
- Standard C libraries (`stdio.h`, `stdlib.h`, and `math.h`)

## Compilation

To compile the program, use the following command in your terminal:

```bash
gcc -o gauss_elimination gauss_elimination.c -lm
