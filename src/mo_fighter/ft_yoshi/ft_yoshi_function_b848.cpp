#pragma force_active on
typedef unsigned int u32;

struct FtYoshiWork {
    char pad[0x1c];
    u32 *m_flagWorks;
};

extern "C" void fn_95_B848(FtYoshiWork *work, u32 value, u32 index)
{
    work->m_flagWorks[index] |= value;
}
