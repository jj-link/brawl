#include <so/so_array.h>

namespace {

struct NessWorkPointers {
    unsigned int* flags;
    int* ints;
    float* floats;
};

struct NessWorkArrays {
    unsigned char prefix[0x10];
    soArrayFixed<int*>* ints;
    soArrayFixed<float*>* floats;
    soArrayFixed<unsigned int*>* flags;
};

}

extern "C" NessWorkPointers fn_101_D62C(NessWorkArrays* work, int index) {
    if (index < 0) {
        NessWorkPointers result = {0, 0, 0};
        return result;
    }

    unsigned int* flags = 0;
    if (index < work->flags->size()) {
        flags = work->flags->at(index);
    }
    int* ints = 0;
    if (index < work->ints->size()) {
        ints = work->ints->at(index);
    }
    float* floats = 0;
    if (index < work->floats->size()) {
        floats = work->floats->at(index);
    }
    NessWorkPointers result = {flags, ints, floats};
    return result;
}
