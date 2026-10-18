#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtSonicArrayOwner
{
    char pad[0xc];
    s32 *m_values;
};

extern "C" void fn_123_A4D8(FtSonicArrayOwner *owner, u32 index)
{
    owner->m_values[index]--;
}
