#include <so/so_array.h>

namespace {

struct NessWorkArrays {
    unsigned char prefix[0x10];
    soArrayFixed<int*>* ints;
    soArrayFixed<float*>* floats;
    soArrayFixed<unsigned int*>* flags;
};

}

extern "C" int fn_101_D524(NessWorkArrays* work) {
    int size = work->flags->size();
    if (size < work->ints->size()) {
        size = work->ints->size();
    }
    if (size < work->floats->size()) {
        size = work->floats->size();
    }
    return size;
}
