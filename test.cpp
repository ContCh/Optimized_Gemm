#include <iostream>

#include "generate.h"



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



template <typename DataType>
void testGenArray(int rows, int cols) {
    DataType* array = genArray<DataType>(rows * cols);
    printArr(array, rows, cols);
}



int main() {
    int rows = 12, cols = 8;

    std::cout << "+ TEST Float:\n";
    testGenArray<float>(rows, cols);

    std::cout << "+ TEST double:\n";
    testGenArray<double>(rows, cols);

    std::cout << "+ TEST INT16_T:\n";
    testGenArray<int16_t>(rows, cols);

    std::cout << "+ TEST UINT8_T:\n";
    testGenArray<uint8_t>(rows, cols);

    std::cout << "+ TEST BOOL :\n";
    testGenArray<bool>(rows, cols);
}
