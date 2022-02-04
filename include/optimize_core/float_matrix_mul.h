#ifndef PROJECT_FLOAT_MATRIX_MUL_H
#define PROJECT_FLOAT_MATRIX_MUL_H

#include <iostream>

template <typename DataType, typename ResultDataType>
void floatMatrixMultiplication(DataType* lhs, DataType* rhs, ResultDataType* result,
                               int rows, int cols, int depth) {
    std::cout << "Float-point situation, need result's type is same as the two matrix."
              << "While get " << typeid(DataType).name() << " and " << typeid(ResultDataType).name();
    return;
}

template <>
void floatMatrixMultiplication<float, float>(float* lhs, float* rhs, float* result,
                                             int rows, int cols, int depth) {
    for (int row = 0; row < rows; row+=4) {
        for (int col =  0; col < cols; col+=4) {

        }
    }
}

template <>
void floatMatrixMultiplication<double, double>(double* lhs, double* rhs, double* result,
                                               int rows, int cols, int depth) {
    for (int row = 0; row < rows; row++) {
        for (int col =  0; col < cols; col++) {
        }
    }
}


#endif //PROJECT_FLOAT_MATRIX_MUL_H