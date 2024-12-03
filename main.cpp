#include <iostream>
#include <cstdio>
#include <cstring>


void multiplyMatrices(const int B[4], const int A[4], int result[4]) {
    result[0] = A[0] * B[0] + A[1] * B[2];
    result[1] = A[0] * B[1] + A[1] * B[3];
    result[2] = A[2] * B[0] + A[3] * B[2];
    result[3] = A[2] * B[1] + A[3] * B[3];
}

void parseMatrix(const char* s, int matrix[4], int& size) {
    size = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            matrix[size++] = s[i] - '0';
        }
    }
}
// Design the stack to store the matrices
void processInput(const char* input) {
    char matrix_string[20];
    // Stack to store the matrices
    int matrix_stack[300][4];
    int stack_size = 0;

    int matrix[4];
    int result[4];
    int matrixA[4];
    int matrixB[4];
    int matrix_size = 0;

    int i = 0, k = 0;

    while (input[i] != '\0') {
        if (input[i] == '[') {
            k = 0;
            i++;
            while (input[i] != ']' && input[i] != '\0') {
                matrix_string[k++] = input[i];
                i++;
            }
            matrix_string[k] = '\0';  // Null-terminate the matrix string
            parseMatrix(matrix_string, matrix, matrix_size);

            for (int j = 0; j < 4; ++j) {
                matrix_stack[stack_size][j] = matrix[j];
            }
            stack_size++;
        } else if (input[i] == ')') {
            stack_size--;
            for (int j = 0; j < 4; ++j)
                matrixA[j] = matrix_stack[stack_size][j];

            stack_size--;
            for (int j = 0; j < 4; ++j)
                matrixB[j] = matrix_stack[stack_size][j];

            multiplyMatrices(matrixA, matrixB, result);
            for (int j = 0; j < 4; ++j)
                matrix_stack[stack_size][j] = result[j];

            stack_size++;
        }
        i++;
    }

    printf("[");
    for (int j = 0; j < 4; ++j) {
        if (j < 3)
            printf("%d,", matrix_stack[stack_size - 1][j]);
        else
            printf("%d", matrix_stack[stack_size - 1][j]);
    }
    printf("]\n");
}

int main() {
    char input[1200];
    while (scanf("%s", input) != EOF) { // Read input until EOF
        processInput(input);
    }

    return 0;
}
