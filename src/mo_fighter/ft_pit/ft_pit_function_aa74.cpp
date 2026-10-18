#pragma force_active on
struct Work {
    unsigned char padding[0x14];
    float* floatWorks;
};

extern "C" void fn_112_AA74(Work* work, float value, unsigned int index) {
    work->floatWorks[index] = value;
}
