#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;

extern s32 fn_803A976C(void *, s32, u32);
extern s32 fn_803AE534(void *, void *, s32, s32, u16, s32, s32);

s32 fn_803AFBB8(void *arg0) {
    char *base = (char *)arg0;
    s32 flags;
    s32 temp_r3;
    s32 temp_r3_2;

    flags = *(s32 *)(base + 0x15E8);
    flags = ((flags & ~1) | 2) & ~4;
    *(s32 *)(base + 0x15E8) = flags;
    fn_803A976C(*(void **)(base + 0x15FC), 0,
                (u32)(*(u16 *)(base + 0x15EC) + *(u16 *)(base + 0x15EE)) << 9);
    temp_r3_2 = fn_803AE534(arg0, base + 0x15F4, *(s32 *)(base + 0x15F0),
                            *(s32 *)(base + 0x15FC), *(u16 *)(base + 0x15EC),
                            *(s32 *)(base + 0x1600), 1);
    if (temp_r3_2 != 0) {
        return temp_r3_2;
    }
    temp_r3 = fn_803AE534(arg0, base + 0x15F8,
                          *(s32 *)(base + 0x15F0) + *(u16 *)(base + 0x15EC) * 0x28,
                          *(s32 *)(base + 0x15FC) + ((u32)*(u16 *)(base + 0x15EC) << 9),
                          *(u16 *)(base + 0x15EE),
                          *(s32 *)(base + 0x1604), 0);
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 0x1F);
}
