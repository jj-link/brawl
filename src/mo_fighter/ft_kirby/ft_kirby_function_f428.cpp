#pragma force_active on
typedef unsigned int u32;

struct FlagWork
{
    unsigned char padding[0x1C];
    u32 *flags;
};

extern "C" u32 fn_96_F428(const FlagWork *work, u32 mask, u32 index)
{
    return (work->flags[index] & mask) != 0;
}
