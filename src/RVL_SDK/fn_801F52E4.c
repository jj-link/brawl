#pragma force_active on
// fn_801F52E4: sets GX clear-mode field (bits 26-31 of GXData+0x80) and flags
// the GXDirtyFlags word (GXData+0x5FC) with bit 0x40000000.

typedef union RegU32 {
    unsigned int _u32;
    struct {
        unsigned int unused : 26;
        unsigned int low6 : 6;
    } bits;
} RegU32;

typedef struct GXData {
    char pad_0x00[0x80];
    RegU32 reg80;
    char pad_0x84[0x5FC - 0x84];
    unsigned int gxDirtyFlags;
} GXData;

extern GXData* const __GXData;

void fn_801F52E4(int mode) {
    __GXData->reg80.bits.low6 = mode & 0x3F;
    __GXData->gxDirtyFlags |= 0x04000000;
}
