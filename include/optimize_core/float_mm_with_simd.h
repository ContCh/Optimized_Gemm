#ifndef FLOAT_MATRIX_MUL_SIMD_H
#define FLOAT_MATRIX_MUL_SIMD_H

#include <iostream>

template <typename DataType>
void addMulImpl(DataType* lhs, DataType* rhs, DataType* result, int depth, int cols) {
    return;
}

template <typename DataType, typename ResultDataType>
void floatMatrixMultiplication(DataType* lhs, DataType* rhs, ResultDataType* result,
                               int rows, int cols, int depth) {
    std::cout << "Operands' type is different from result's. Get "
              << typeid(DataType).name() << " and " << typeid(ResultDataType).name() << '\n';
    return;
}


template <>
void floatMatrixMultiplication<float, float>(float* lhs, float* rhs, float* result,
                                             int rows, int cols, int depth) {
    for (int row = 0; row < rows; row+=4) {
        for (int col =  0; col < cols; col+=4) {
            addMulImpl(&lhs[row * depth], &rhs[col], &result[row * cols + col], depth, cols);
        }
    }
}

template <>
void floatMatrixMultiplication<double, double>(double* lhs, double* rhs, double* result,
                                             int rows, int cols, int depth) {
    for (int row = 0; row < rows; row+=4) {
        for (int col =  0; col < cols; col+=4) {
            addMulImpl(&lhs[row * depth], &rhs[col], &result[row * cols + col], depth, cols);
        }
    }
}


#endif // FLOAT_MATRIX_MUL_SIMD_H
