#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>

#include <type_traits>


#define RANDOM(x, y) (rand() % (y - x) + x)


namespace std {
template <typename DataType>
struct is_bool : public false_type {};

template <>
struct is_bool<bool> : public true_type {};
}

// Judge if fixed-point datatype is signed number.
template <typename DataType>
bool isSignedInteger() {
    int bit_width = sizeof(DataType) * 8;
    DataType int_min = static_cast<DataType>(1l << (bit_width - 1));
    return int_min < 0;
}

/* Random generate fixed-point array of target length
 * Fixed-Point scale is set here [INT_MIN, INT_MAX].
 * For example, int8_t  -->  [-128, 127]
 */
template <typename DataType>
void genFixedPointKernel(DataType* gen_array, int length) {
    int bit_width = sizeof(DataType) * 8;
    assert(bit_width <= 16);
    int int_min = 0;
    int int_max = std::pow(2, bit_width) - 1;
    if (isSignedInteger<DataType>()) {
        int offset = - std::pow(2, bit_width - 1);
        int_min += offset;
        int_max += offset;
    }

    srand((int)time(0));
    for (int idx = 0; idx < length; idx++) {
        DataType gen_val = RANDOM(int_min, int_max);
        gen_array[idx] = gen_val;
    }
}

/* Random generate float-point array similar to genFixedPointKernel
 * Support double and float type.
 * Both are scaled into [-1, 1].
 */
template <typename DataType>
void genFloatPointKernel(DataType* gen_array, int length) {
    srand((int)time(0));
    for (int idx = 0; idx < length; idx++) {
        DataType gen_val = rand() / double(RAND_MAX);
        gen_val = gen_val * 2 - 1;
        gen_array[idx] = gen_val;
    }
}

// Array generation randomly
template <typename DataType>
DataType* genArray(int num_elems) {
    DataType* pointer = new DataType[num_elems];
    if (std::is_integral<DataType>::value && !std::is_bool<DataType>::value) {
        genFixedPointKernel(pointer, num_elems);
    } else if (std::is_floating_point<DataType>::value) {
        genFloatPointKernel(pointer, num_elems);
    } else {
        assert("Given type is not FLOAT or INT, Abort!" && false);
    }
    return pointer;
}
