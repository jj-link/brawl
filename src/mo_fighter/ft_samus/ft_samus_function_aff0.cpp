#pragma force_active on
struct Work {
    unsigned char padding[0x14];
    float* floatWorks;
};

extern "C" void fn_94_AFF0(Work* work, float value, unsigned int index) {
    work->floatWorks[index] = value;
}
