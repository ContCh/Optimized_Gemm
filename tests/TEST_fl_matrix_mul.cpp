#include <string.h>
#include <iostream>
#include "clocks.h"
#include "generate.h"
#include "optimize_core/float_matrix_mul.h"
#include "matrix_mul_base.h"

#define Row   600
#define Depth 800
#define Col   600

int main() {
    float* matrix_left = genArray<float>(Row * Depth);
    float* matrix_right = genArray<float>(Depth * Col);

    float* result = new float[Row * Col];
    memset(result, 0, Row * Col * sizeof(float));

    clock_start();
    floatMatrixMultiplication(matrix_left, matrix_right, result,
                              Row, Col, Depth);
    auto dura = clock_end(MICROSEC);
    std::cout << "Cost " << dura << " us." << std::endl;

    float* bm_result = new float[Row * Col];
    memset(result, 0, Row * Col * sizeof(float));
    bmMatrixMultiplication(matrix_left, matrix_right, bm_result,
                           Row, Col, Depth);
    
    std::cout << benchmarkCompare(bm_result, result, Row, Col, 0.001) << '\n';

}
