#pragma force_active on
struct FlagWork {
    char pad[0x1c];
    unsigned int *m_flagWorks;
};

extern "C" void fn_92_9A18(FlagWork *work, unsigned int mask, unsigned int index) {
    work->m_flagWorks[index] |= mask;
}
