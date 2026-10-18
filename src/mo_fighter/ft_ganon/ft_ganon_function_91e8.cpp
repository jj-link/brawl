#pragma force_active on
typedef unsigned int u32;

struct FtGanonWork {
    char pad[0x1c];
    u32 *flags;
};

extern "C" void fn_109_91E8(FtGanonWork *work, u32 mask, u32 index)
{
    work->flags[index] &= ~mask;
}
