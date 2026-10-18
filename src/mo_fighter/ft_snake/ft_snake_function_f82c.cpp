#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct ftSnakeWork {
    char pad[0xC];
    s32* m_intWorks;
};

extern "C" void fn_122_F82C(ftSnakeWork* work, s32 value, u32 index) {
    work->m_intWorks[index] -= value;
}
