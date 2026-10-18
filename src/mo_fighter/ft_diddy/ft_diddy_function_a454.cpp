#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct FtWork {
    char pad[0xc];
    s32* m_intWorks;
};

extern "C" void fn_115_A454(FtWork* work, s32 value, u32 index) {
    work->m_intWorks[index] -= value;
}
