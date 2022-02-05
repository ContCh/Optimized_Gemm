#ifndef PROJECT_MATRIX_MUL_BASE_H
#define PROJECT_MATRIX_MUL_BASE_H

template <typename DataType, typename ResultDataType>
void eltwiseAddMul(DataType* lhs, DataType* rhs, ResultDataType* result) {
    DataType mul_res = (*lhs) * (*rhs);
    *result += mul_res;
}


/* Just provide standard matrix multipication
 * This function's results will be regarded as benchmark
 * verify if optimized gemm function is implemented correctly.
 */
// Here default is Row-major matrix.
template <typename DataType, typename ResultDataType>
void bmMatrixMultiplication(DataType* lhs, DataType* rhs, ResultDataType* result,
                            int rows, int cols, int depth) {
    for (int row_it = 0; row_it < rows; row_it++) {
        for (int idx = 0; idx < depth; idx++) {
            for (int col_it = 0; col_it < cols; col_it++) {
                // (row_it, col_it) = (row_it, idx) * (idx, col_it)
                eltwiseAddMul(&lhs[row_it * depth + idx], &rhs[idx * cols + col_it],
                              &result[row_it * cols + col_it]);
            }
        }
    }
}

template <typename DataType>
bool benchmarkCompare(DataType* arr_base, DataType* arr_test,
                      int rows, int cols, double threshold) {
    for (int idx = 0; idx < rows * cols; idx++) {
        if (std::abs(arr_base[idx] - arr_test[idx]) > threshold) {
            std::cout << '(' << (idx / cols) << ", " << (idx % cols) << ") diff-> "
                      << arr_base[idx] << " while get " << arr_test[idx] << std::endl;
            return false;
        }
    }
    return true;
}

#endif //PROJECT_MATRIX_MUL_BASE_H
