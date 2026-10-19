#pragma force_active on
struct Work {
    unsigned int padding[3];
    unsigned int* values;
};

extern "C" unsigned int fn_93_B3B4(const Work* work, unsigned int index) {
    return work->values[index];
}
