#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;

extern s32 fn_803D634C(void *, s32, u32);
extern s32 fn_803D8EC0(void *, void *, s32, s32, u16, s32, s32);

s32 fn_803DA314(void *arg0) {
    char *base = (char *)arg0;
    s32 flags;
    s32 temp_r3;
    s32 temp_r3_2;

    flags = *(s32 *)(base + 0x1624);
    flags = ((flags & ~1) | 2) & ~4;
    *(s32 *)(base + 0x1624) = flags;
    fn_803D634C(*(void **)(base + 0x1638), 0,
                (u32)(*(u16 *)(base + 0x1628) + *(u16 *)(base + 0x162A)) << 9);
    temp_r3_2 = fn_803D8EC0(arg0, base + 0x1630, *(s32 *)(base + 0x162C),
                            *(s32 *)(base + 0x1638), *(u16 *)(base + 0x1628),
                            *(s32 *)(base + 0x163C), 1);
    if (temp_r3_2 != 0) {
        return temp_r3_2;
    }
    temp_r3 = fn_803D8EC0(arg0, base + 0x1634,
                          *(s32 *)(base + 0x162C) + *(u16 *)(base + 0x1628) * 0x28,
                          *(s32 *)(base + 0x1638) + ((u32)*(u16 *)(base + 0x1628) << 9),
                          *(u16 *)(base + 0x162A),
                          *(s32 *)(base + 0x1640), 0);
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 0x1F);
}
