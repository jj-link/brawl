#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct FlagWork {
    u8 pad[0x1c];
    u32 *flags;
};

extern "C" void fn_120_9A44(FlagWork *work, u32 mask, u32 index) {
    work->flags[index] |= mask;
}
