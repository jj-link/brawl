#pragma force_active on
namespace {

struct NessWorkPointers {
    unsigned int* flags;
    int* ints;
    float* floats;
};

struct NessWorkArrays;

}

extern "C" NessWorkPointers fn_101_D62C(NessWorkArrays* work, int index);

extern "C" NessWorkPointers* fn_101_D758(NessWorkArrays* work, int index) {
    return (NessWorkPointers*)(void*)&fn_101_D62C(work, index);
}
