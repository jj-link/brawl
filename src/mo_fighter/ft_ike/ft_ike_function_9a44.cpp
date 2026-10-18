#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtIkeWork
{
    char pad[0xC];
    s32 *m_values;
};

extern "C" void fn_119_9A44(FtIkeWork *work, s32 value, u32 index)
{
    work->m_values[index] -= value;
}
