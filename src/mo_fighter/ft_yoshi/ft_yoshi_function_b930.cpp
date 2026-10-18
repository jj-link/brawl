#pragma force_active on
struct FtYoshiIntWork {
    char pad[0xC];
    int* intWorks;
};

extern "C" void fn_95_B930(FtYoshiIntWork* work, int value, unsigned int index) {
    if (0 != value) {
        work->intWorks[index] /= value;
    }
}
