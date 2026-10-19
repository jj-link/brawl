#pragma force_active on
struct GanonWork {
    unsigned char padding[0xC];
    int* intWorks;
};

extern "C" void fn_109_9364(GanonWork* work, int value, unsigned int index) {
    work->intWorks[index] = value;
}
