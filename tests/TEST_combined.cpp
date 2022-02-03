#include <string.h>
#include <iostream>
#include "clocks.h"
#include "generate.h"
#include "matrix_mul_base.h"

#define Row   400
#define Depth 600
#define Col   500


template <typename DataType>
void printArr(DataType* data_arr, int rows, int cols) {
    std::cout << "------------------------\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sizeof(DataType) > 2) {
                std::cout << data_arr[i * cols + j];
            } else {
                std::cout << static_cast<int>(data_arr[i*cols + j]);
            }
            std::cout << (j == cols - 1 ? '\n' : '\t');
        }
    }
    std::cout << '\n';
}

int main() {
    float* matrix_left = genArray<float>(Row * Depth);
    float* matrix_right = genArray<float>(Depth * Col);
#if (Row < 10) && (Depth < 10)
    std::cout << "LHS :\n";
    printArr(matrix_left, Row, Depth);
    std::cout << "RHS :\n";
    printArr(matrix_right, Depth, Col);
#endif

    float* result = new float[Row * Col];
    memset(result, 0, Row * Col * sizeof(float));

    clock_start();
    bmMatrixMultiplication(matrix_left, matrix_right, result,
                           Row, Col, Depth);
    auto dura = clock_end(MICROSEC);
    std::cout << "Cost " << dura << " us." << std::endl;
#if (Row < 10) && (Col < 10)
    printArr(result, Row, Col);
#endif
}