#include <iostream>
#include <vector>

// Function to shift a row to the left
void shift_left(std::vector<std::vector<int>>& mat, int row, int n, int amount) {
    std::vector<int> temp_buffer(n);

    for (int j = 0; j < n; j++) {
        temp_buffer[j] = mat[row][(j + amount) % n];
    }

    mat[row] = temp_buffer;
}

// Function to shift a column up
void shift_up(std::vector<std::vector<int>>& mat, int col, int n, int amount) {
    std::vector<int> temp_buffer(n);

    for (int i = 0; i < n; i++) {
        temp_buffer[i] = mat[(i + amount) % n][col];
    }

    for (int i = 0; i < n; i++) {
        mat[i][col] = temp_buffer[i];
    }
}

// Function to print a matrix
void print_matrix(const std::vector<std::vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the matrix (n x n): ";
    std::cin >> n;

    std::vector<std::vector<int>> matA(n, std::vector<int>(n));
    std::vector<std::vector<int>> matB(n, std::vector<int>(n));
    std::vector<std::vector<int>> matA1(n, std::vector<int>(n));
    std::vector<std::vector<int>> matB1(n, std::vector<int>(n));
    std::vector<std::vector<int>> matC1(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> matA2(n, std::vector<int>(n));
    std::vector<std::vector<int>> matB2(n, std::vector<int>(n));
    std::vector<std::vector<int>> matC2(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> matA3(n, std::vector<int>(n));
    std::vector<std::vector<int>> matB3(n, std::vector<int>(n));
    std::vector<std::vector<int>> matC3(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> matA4(n, std::vector<int>(n));
    std::vector<std::vector<int>> matB4(n, std::vector<int>(n));
    std::vector<std::vector<int>> matC4(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> final_result(n, std::vector<int>(n, 0));

    // Take input for Matrix A
    std::cout << "Enter elements for Matrix A (" << n << " x " << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matA[i][j];
        }
    }

    // Take input for Matrix B
    std::cout << "Enter elements for Matrix B (" << n << " x " << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matB[i][j];
        }
    }

    std::cout << "Matrix A:\n";
    print_matrix(matA);
    std::cout << "Matrix B:\n";
    print_matrix(matB);

    // Perform initial shifts for A1 and B1
    matA1 = matA;
    for (int i = 0; i < n; i++) {
        shift_left(matA1, i, n, i);
    }

    matB1 = matB;
    for (int j = 0; j < n; j++) {
        shift_up(matB1, j, n, j);
    }

    std::cout << "Matrix A1 after row shifts:\n";
    print_matrix(matA1);
    std::cout << "Matrix B1 after column shifts:\n";
    print_matrix(matB1);

    // Calculate C1 = A1 * B1 (element-wise multiplication)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matC1[i][j] = matA1[i][j] * matB1[i][j];
        }
    }
    std::cout << "Matrix C1 = A1 * B1 (element-wise multiplication):\n";
    print_matrix(matC1);

    // Perform subsequent shifts and calculations for A2, B2, C2
    matA2 = matA1;
    for (int i = 0; i < n; i++) {
        shift_left(matA2, i, n, 1);
    }
    matB2 = matB1;
    for (int j = 0; j < n; j++) {
        shift_up(matB2, j, n, 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matC2[i][j] = matA2[i][j] * matB2[i][j];
        }
    }
    std::cout << "Matrix A2 after 1 left shift:\n";
    print_matrix(matA2);
    std::cout << "Matrix B2 after 1 up shift:\n";
    print_matrix(matB2);
    std::cout << "Matrix C2 = A2 * B2 (element-wise multiplication):\n";
    print_matrix(matC2);

    // Perform subsequent shifts and calculations for A3, B3, C3
    matA3 = matA2;
    for (int i = 0; i < n; i++) {
        shift_left(matA3, i, n, 1);
    }
    matB3 = matB2;
    for (int j = 0; j < n; j++) {
        shift_up(matB3, j, n, 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matC3[i][j] = matA3[i][j] * matB3[i][j];
        }
    }
    std::cout << "Matrix A3 after 1 left shift:\n";
    print_matrix(matA3);
    std::cout << "Matrix B3 after 1 up shift:\n";
    print_matrix(matB3);
    std::cout << "Matrix C3 = A3 * B3 (element-wise multiplication):\n";
    print_matrix(matC3);

    // Perform subsequent shifts and calculations for A4, B4, C4
    matA4 = matA3;
    for (int i = 0; i < n; i++) {
        shift_left(matA4, i, n, 1);
    }
    matB4 = matB3;
    for (int j = 0; j < n; j++) {
        shift_up(matB4, j, n, 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matC4[i][j] = matA4[i][j] * matB4[i][j];
        }
    }
    std::cout << "Matrix A4 after 1 left shift:\n";
    print_matrix(matA4);
    std::cout << "Matrix B4 after 1 up shift:\n";
    print_matrix(matB4);
    std::cout << "Matrix C4 = A4 * B4 (element-wise multiplication):\n";
    print_matrix(matC4);

    // Calculate the final result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            final_result[i][j] = matC1[i][j] + matC2[i][j] + matC3[i][j] + matC4[i][j];
        }
    }

    std::cout << "Final Result Matrix C = C1 + C2 + C3 + C4:\n";
    print_matrix(final_result);

    return 0;
}
/*
Enter the size of the matrix (n x n): 4
Enter elements for Matrix A (4 x 4):
2 3 4 5
9 8 7 6
5 4 2 3
8 7 3 4
Enter elements for Matrix B (4 x 4):
3 5 7 6
2 7 6 3
7 5 3 2
4 3 2 5
ans 
60 66 54 54 
116 154 144 122 
49 72 71 61 
75 116 115 95 */

/*

code meaning 


#include <iostream>  // Include the input-output stream library for console input/output operations
#include <vector>  // Include the vector library to use dynamic arrays (2D matrices here)

// Function to shift a row to the left
void shift_left(std::vector<std::vector<int>>& mat, int row, int n, int amount) {
    std::vector<int> temp_buffer(n);  // Create a temporary 1D vector to hold the shifted row elements

    for (int j = 0; j < n; j++) {  // Loop through each element in the row
        temp_buffer[j] = mat[row][(j + amount) % n];  // Shift the element to the left by 'amount' positions and wrap around using modulo
    }

    mat[row] = temp_buffer;  // Replace the original row with the shifted row
}

// Function to shift a column up
void shift_up(std::vector<std::vector<int>>& mat, int col, int n, int amount) {
    std::vector<int> temp_buffer(n);  // Create a temporary 1D vector to hold the shifted column elements

    for (int i = 0; i < n; i++) {  // Loop through each element in the column
        temp_buffer[i] = mat[(i + amount) % n][col];  // Shift the element up by 'amount' positions and wrap around using modulo
    }

    for (int i = 0; i < n; i++) {  // Loop again to put the shifted values back into the matrix
        mat[i][col] = temp_buffer[i];  // Update the original matrix with the shifted column values
    }
}

// Function to print a matrix
void print_matrix(const std::vector<std::vector<int>>& mat) {
    for (const auto& row : mat) {  // Loop through each row in the matrix
        for (int elem : row) {  // Loop through each element in the row
            std::cout << elem << " ";  // Print the element followed by a space
        }
        std::cout << std::endl;  // Print a newline after each row to format the matrix
    }
}

int main() {
    int n;  // Declare a variable to store the matrix size
    std::cout << "Enter the size of the matrix (n x n): ";  // Ask the user for the size of the matrix
    std::cin >> n;  // Take the size input from the user

    // Declare 2D vectors for matrices A, B, A1, B1, C1, A2, B2, C2, A3, B3, C3, A4, B4, C4, and the final result
    std::vector<std::vector<int>> matA(n, std::vector<int>(n));  // Matrix A initialized with size n x n
    std::vector<std::vector<int>> matB(n, std::vector<int>(n));  // Matrix B initialized with size n x n
    std::vector<std::vector<int>> matA1(n, std::vector<int>(n));  // Matrix A1, a shifted version of A
    std::vector<std::vector<int>> matB1(n, std::vector<int>(n));  // Matrix B1, a shifted version of B
    std::vector<std::vector<int>> matC1(n, std::vector<int>(n, 0));  // Result matrix C1 initialized to zero
    std::vector<std::vector<int>> matA2(n, std::vector<int>(n));  // Matrix A2
    std::vector<std::vector<int>> matB2(n, std::vector<int>(n));  // Matrix B2
    std::vector<std::vector<int>> matC2(n, std::vector<int>(n, 0));  // Result matrix C2 initialized to zero
    std::vector<std::vector<int>> matA3(n, std::vector<int>(n));  // Matrix A3
    std::vector<std::vector<int>> matB3(n, std::vector<int>(n));  // Matrix B3
    std::vector<std::vector<int>> matC3(n, std::vector<int>(n, 0));  // Result matrix C3 initialized to zero
    std::vector<std::vector<int>> matA4(n, std::vector<int>(n));  // Matrix A4
    std::vector<std::vector<int>> matB4(n, std::vector<int>(n));  // Matrix B4
    std::vector<std::vector<int>> matC4(n, std::vector<int>(n, 0));  // Result matrix C4 initialized to zero
    std::vector<std::vector<int>> final_result(n, std::vector<int>(n, 0));  // Final result matrix initialized to zero

    // Take input for Matrix A from the user
    std::cout << "Enter elements for Matrix A (" << n << " x " << n << "):\n";
    for (int i = 0; i < n; i++) {  // Loop through each row of Matrix A
        for (int j = 0; j < n; j++) {  // Loop through each column of Matrix A
            std::cin >> matA[i][j];  // Take input for each element of Matrix A
        }
    }

    // Take input for Matrix B from the user
    std::cout << "Enter elements for Matrix B (" << n << " x " << n << "):\n";
    for (int i = 0; i < n; i++) {  // Loop through each row of Matrix B
        for (int j = 0; j < n; j++) {  // Loop through each column of Matrix B
            std::cin >> matB[i][j];  // Take input for each element of Matrix B
        }
    }

    std::cout << "Matrix A:\n";
    print_matrix(matA);  // Print Matrix A to the console
    std::cout << "Matrix B:\n";
    print_matrix(matB);  // Print Matrix B to the console

    // Perform initial shifts for A1 and B1
    matA1 = matA;  // Copy Matrix A into A1
    for (int i = 0; i < n; i++) {  // Loop through each row of A1
        shift_left(matA1, i, n, i);  // Shift each row of A1 to the left by 'i' positions
    }

    matB1 = matB;  // Copy Matrix B into B1
    for (int j = 0; j < n; j++) {  // Loop through each column of B1
        shift_up(matB1, j, n, j);  // Shift each column of B1 upwards by 'j' positions
    }

    std::cout << "Matrix A1 after row shifts:\n";
    print_matrix(matA1);  // Print Matrix A1 after the shifts
    std::cout << "Matrix B1 after column shifts:\n";
    print_matrix(matB1);  // Print Matrix B1 after the shifts

    // Calculate C1 = A1 * B1 (element-wise multiplication)
    for (int i = 0; i < n; i++) {  // Loop through rows of C1
        for (int j = 0; j < n; j++) {  // Loop through columns of C1
            matC1[i][j] = matA1[i][j] * matB1[i][j];  // Multiply corresponding elements of A1 and B1 and store in C1
        }
    }
    std::cout << "Matrix C1 = A1 * B1 (element-wise multiplication):\n";
    print_matrix(matC1);  // Print Matrix C1

    // Perform subsequent shifts and calculations for A2, B2, C2
    matA2 = matA1;  // Copy Matrix A1 into A2
    for (int i = 0; i < n; i++) {  // Loop through rows of A2
        shift_left(matA2, i, n, 1);  // Shift each row of A2 to the left by 1 position
    }
    matB2 = matB1;  // Copy Matrix B1 into B2
    for (int j = 0; j < n; j++) {  // Loop through columns of B2
        shift_up(matB2, j, n, 1);  // Shift each column of B2 upwards by 1 position
    }

    for (int i = 0; i < n; i++) {  // Loop through rows of C2
        for (int j = 0; j < n; j++) {  // Loop through columns of C2
            matC2[i][j] = matA2[i][j] * matB2[i][j];  // Multiply corresponding elements of A2 and B2 and store in C2
        }
    }
    std::cout << "Matrix A2 after 1 left shift:\n";
    print_matrix(matA2);  // Print Matrix A2 after the shift
    std::cout << "Matrix B2 after 1 up shift:\n";
    print_matrix(matB2);  // Print Matrix B2 after the shift
    std::cout << "Matrix C2 = A2 * B2 (element-wise multiplication):\n";
    print_matrix(matC2);  // Print Matrix C2

    // Repeat similar steps for A3, B3, C3 and A4, B4, C4

    // Sum the results from C1, C2, C3, and C4 to get the final result matrix
    for (int i = 0; i < n; i++) {  // Loop through rows of the final result matrix
        for (int j = 0; j < n; j++) {  // Loop through columns of the final result matrix
            final_result[i][j] = matC1[i][j] + matC2[i][j] + matC3[i][j] + matC4[i][j];  // Sum corresponding elements of C1, C2, C3, and C4
        }
    }

    std::cout << "Final Result Matrix C = C1 + C2 + C3 + C4:\n";
    print_matrix(final_result);  // Print the final result matrix

    return 0;  // Return 0 to indicate successful execution of the program
}

*/