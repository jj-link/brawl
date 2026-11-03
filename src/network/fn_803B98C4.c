#pragma force_active on

typedef unsigned long u32;
typedef long s32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 unk0;
    char pad2[0x1E];
    u8 unk20;
    char pad21[7];
    u32 unk28;
    char pad2c[8];
    s32 unk34;
} Unk;

extern s32 fn_803BFFC8(void *, u32 *, u16, u16, s32);
extern s32 fn_803C0360(void *, u32 *, u16, u16, s32);

static u32 bswap32(u32 x) {
    return (x >> 24) | ((x >> 8) & 0xFF00) | ((x << 8) & 0xFF0000) | (x << 24);
}

s32 fn_803B98C4(Unk *arg0, u32 arg1, u32 arg2) {
    u32 sp8;
    u32 temp_r8_2;
    u16 off;
    u16 mask;
    s32 ret;
    u32 r9;

    if (arg0 == 0) {
        return 0xA;
    }
    if ((arg1 < 2 || arg1 >= (u32)(arg0->unk34 + 2)) && arg1 != 0 && arg1 != 1) {
        return 0xE;
    }
    temp_r8_2 = arg1 * 4;
    off = (u16)(arg0->unk28 + (temp_r8_2 >> arg0->unk20));
    mask = (u16)(temp_r8_2 & (arg0->unk0 - 1));
    ret = fn_803BFFC8(arg0, &sp8, off, mask, 4);
    if (ret != 0) {
        return ret;
    }
    r9 = (bswap32(sp8) & 0xF0000000) | (arg2 & 0x0FFFFFFF);
    sp8 = bswap32(r9);
    return fn_803C0360(arg0, &sp8, off, mask, 4);
}
