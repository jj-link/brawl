#pragma force_active on
struct FtZakoWork {
    char pad[0xc];
    int* m_intWorks;
};

extern "C" void fn_126_765C(FtZakoWork* work, int value, unsigned int index) {
    work->m_intWorks[index] -= value;
}
