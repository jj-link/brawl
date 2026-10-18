#pragma force_active on
typedef unsigned int u32;

struct FighterWork {
    char pad[0x1c];
    u32 *flags;
};

extern "C" void fn_108_B1B0(FighterWork *work, u32 mask, u32 index)
{
    work->flags[index] |= mask;
}
