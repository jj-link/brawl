#pragma force_active on
typedef unsigned int u32;

struct FighterWork {
    char pad[0x1c];
    u32 *m_flags;
};

extern "C" void fn_97_B314(FighterWork *work, u32 mask, u32 index) {
    work->m_flags[index] &= ~mask;
}
