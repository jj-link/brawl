#pragma force_active on
typedef unsigned int u32;

struct FlagWork {
    u32 m_pad[7];
    u32 *m_flags;
};

extern "C" void fn_112_A9B8(FlagWork *work, u32 mask, u32 index)
{
    work->m_flags[index] &= ~mask;
}
