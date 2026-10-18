#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct FtSonicWork {
    u8 pad[0xc];
    s32 *m_values;
};

extern "C" void fn_123_A540(FtSonicWork *work, s32 value, u32 index)
{
    work->m_values[index] -= value;
}
