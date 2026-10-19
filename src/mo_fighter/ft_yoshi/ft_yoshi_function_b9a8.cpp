#pragma force_active on
struct Work {
    unsigned char padding[0xC];
    int* values;
};

extern "C" int fn_95_B9A8(const Work* work, unsigned int index) {
    return work->values[index];
}
