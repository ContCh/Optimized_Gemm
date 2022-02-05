#ifndef PROJECT_FLOAT_MATRIX_MUL_H
#define PROJECT_FLOAT_MATRIX_MUL_H

#include <iostream>

template <typename DataType>
void addMulImpl(DataType* lhs, DataType* rhs, DataType* result, int depth, int cols) {
    DataType res_r0_c0, res_r0_c1, res_r0_c2, res_r0_c3,
             res_r1_c0, res_r1_c1, res_r1_c2, res_r1_c3,
             res_r2_c0, res_r2_c1, res_r2_c2, res_r2_c3,
             res_r3_c0, res_r3_c1, res_r3_c2, res_r3_c3;
    res_r0_c0 = res_r0_c1 = res_r0_c2 = res_r0_c3 = 0;
    res_r1_c0 = res_r1_c1 = res_r1_c2 = res_r1_c3 = 0;
    res_r2_c0 = res_r2_c1 = res_r2_c2 = res_r2_c3 = 0;
    res_r3_c0 = res_r3_c1 = res_r3_c2 = res_r3_c3 = 0;

    DataType* lhs_r0_ptr = lhs;
    DataType* lhs_r1_ptr = lhs_r0_ptr + depth;
    DataType* lhs_r2_ptr = lhs_r1_ptr + depth;
    DataType* lhs_r3_ptr = lhs_r2_ptr + depth;

    for (int idx = 0; idx < depth; idx++) {
        DataType lhs_r0 = *lhs_r0_ptr++;
        DataType lhs_r1 = *lhs_r1_ptr++;
        DataType lhs_r2 = *lhs_r2_ptr++;
        DataType lhs_r3 = *lhs_r3_ptr++;
        DataType rhs_c0 = *rhs;
        DataType rhs_c1 = *(rhs + 1);
        DataType rhs_c2 = *(rhs + 2);
        DataType rhs_c3 = *(rhs + 3);

        res_r0_c0 += lhs_r0 * rhs_c0; res_r0_c1 += lhs_r0 * rhs_c1;
        res_r0_c2 += lhs_r0 * rhs_c2; res_r0_c3 += lhs_r0 * rhs_c3;

        res_r1_c0 += lhs_r1 * rhs_c0; res_r1_c1 += lhs_r1 * rhs_c1;
        res_r1_c2 += lhs_r1 * rhs_c2; res_r1_c3 += lhs_r1 * rhs_c3;

        res_r2_c0 += lhs_r2 * rhs_c0; res_r2_c1 += lhs_r2 * rhs_c1;
        res_r2_c2 += lhs_r2 * rhs_c2; res_r2_c3 += lhs_r2 * rhs_c3;

        res_r3_c0 += lhs_r3 * rhs_c0; res_r3_c1 += lhs_r3 * rhs_c1;
        res_r3_c2 += lhs_r3 * rhs_c2; res_r3_c3 += lhs_r3 * rhs_c3;

        rhs += cols;
    }

    result[0] = res_r0_c0; result[1] = res_r0_c1;
    result[2] = res_r0_c2; result[3] = res_r0_c3;

    result[cols] = res_r1_c0; result[cols + 1] = res_r1_c1;
    result[cols + 2] = res_r1_c2; result[cols + 3] = res_r1_c3;

    result[cols * 2] = res_r2_c0; result[cols * 2 + 1] = res_r2_c1;
    result[cols * 2 + 2] = res_r2_c2; result[cols * 2 + 3] = res_r2_c3;

    result[cols * 3] = res_r3_c0; result[cols * 3 + 1] = res_r3_c1;
    result[cols * 3 + 2] = res_r3_c2; result[cols * 3 + 3] = res_r3_c3;
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


#endif //PROJECT_FLOAT_MATRIX_MUL_H
