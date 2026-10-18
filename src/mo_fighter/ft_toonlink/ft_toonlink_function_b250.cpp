#pragma force_active on
struct FlagWork
{
    char pad[0x1c];
    unsigned int *m_flags;
};

extern "C" void fn_121_B250(FlagWork *work, unsigned int mask, unsigned int index)
{
    work->m_flags[index] |= mask;
}
