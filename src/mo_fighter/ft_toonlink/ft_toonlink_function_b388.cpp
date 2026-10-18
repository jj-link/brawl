#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtToonWork {
    char pad[0xc];
    s32 *m_values;
};

extern "C" void fn_121_B388(FtToonWork *work, s32 value, u32 index)
{
    work->m_values[index] += value;
}
