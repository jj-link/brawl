#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct FtWork {
    u8 pad[0x1c];
    u32 *m_flags;
};

extern "C" void fn_104_A9CC(FtWork *work, u32 mask, u32 index)
{
    u32 *flags = work->m_flags;
    flags[index] &= ~mask;
}
