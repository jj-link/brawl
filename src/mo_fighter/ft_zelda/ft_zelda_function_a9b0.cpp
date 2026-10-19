#pragma force_active on
typedef unsigned int u32;

struct FlagWork {
    char pad[0x1c];
    u32 *flags;
};

extern "C" bool fn_104_A9B0(const FlagWork *work, u32 mask, u32 index) {
    return (work->flags[index] & mask) != 0;
}
