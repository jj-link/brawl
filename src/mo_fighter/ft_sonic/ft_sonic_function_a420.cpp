#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct SonicWork {
    u8 m_pad[0x1c];
    u32* m_flags;
};

extern "C" void fn_123_A420(SonicWork* work, u32 mask, u32 index)
{
    work->m_flags[index] |= mask;
}
