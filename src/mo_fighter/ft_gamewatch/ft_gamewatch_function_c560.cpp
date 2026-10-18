#pragma force_active on
typedef unsigned int u32;

struct FtGamewatchWork {
    char pad[0x1c];
    u32 *m_flagWorks;
};

extern "C" void fn_107_C560(FtGamewatchWork *work, u32 mask, u32 index) {
    work->m_flagWorks[index] |= mask;
}
