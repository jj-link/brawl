#pragma force_active on
struct Work {
    char padding[12];
    int *m_intWorks;
};

extern "C" void fn_92_9B00(Work *work, int value, unsigned int index) {
    if (value != 0) {
        work->m_intWorks[index] /= value;
    }
}
