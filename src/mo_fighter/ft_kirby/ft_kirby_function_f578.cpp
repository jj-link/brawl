#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtWork {
    char pad[0xc];
    s32* m_intWorks;
};

extern "C" void fn_96_F578(FtWork* work, s32 value, u32 index) {
    work->m_intWorks[index] *= value;
}
