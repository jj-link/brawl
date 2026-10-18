#pragma force_active on
struct WorkSimple {
    char pad[0xC];
    int* m_intWorks;
};

extern "C" void fn_104_AAE0(WorkSimple* work, int value, unsigned int index) {
    if (0 != value) {
        work->m_intWorks[index] /= value;
    }
}
