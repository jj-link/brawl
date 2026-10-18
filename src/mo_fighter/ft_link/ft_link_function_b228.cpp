#pragma force_active on
typedef unsigned int u32;

struct FlagWork {
    char pad[0x1c];
    u32* m_flags;
};

extern "C" void fn_93_B228(FlagWork* work, u32 mask, u32 index) {
    work->m_flags[index] &= ~mask;
}
