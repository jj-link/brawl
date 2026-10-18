#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct FighterWorkBase {
    u8 pad[0x1c];
    u32 *flags;
};

extern "C" void fn_115_A334(FighterWorkBase *work, u32 mask, u32 index) {
    work->flags[index] |= mask;
}
