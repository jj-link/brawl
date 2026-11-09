#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *fn_80204768(void *, s32, s32);
extern void *fn_803CD3D8(void);
extern s32 fn_803D5870(s32);
extern void fn_803D5878(void *, s32, void *, u16);
extern void *memset(void *, s32, u32);
void fn_803D55D4(void *arg0) {
    s32 i;
    s32 l;
    s32 j;
    s32 *slot;
    u8 *p;
    s32 k;
    u8 *buf;
    u8 *base;
    base = (u8 *)fn_803CD3D8();
    slot = (s32 *)base;
    for (k = 0; k < 4; k++) {
        buf = (u8 *)fn_80204768(arg0, 0x2F0, 0x20);
        *slot = (s32)buf;
        p = buf + 8;
        *(s32 *)buf = 0x524E4344;
        *(s16 *)(buf + 4) = 0;
        *(s16 *)(buf + 0x2EC) = 0;
        *(s16 *)(buf + 0x2EE) = 0;
        for (i = 0; i < 10; i++) {
            memset(p, 0, 0x4A);
            p += 0x4A;
        }
        slot[4] = 0;
        slot++;
    }
    buf = (u8 *)fn_80204768(arg0, 0x2F0, 0x20);
    *(void **)(base + 0x20) = buf;
    *(s32 *)buf = 0x524E4344;
    *(s16 *)(buf + 4) = 0;
    *(s16 *)(buf + 0x2EC) = 0;
    *(s16 *)(buf + 0x2EE) = 0;
    p = buf + 8;
    for (j = 0; j < 10; j++) {
        memset(p, 0, 0x4A);
        p += 0x4A;
    }
    buf = (u8 *)fn_80204768(arg0, 0x2F0, 0x20);
    *(void **)(base + 0x24) = buf;
    *(s32 *)buf = 0x524E4344;
    *(s16 *)(buf + 4) = 0;
    *(s16 *)(buf + 0x2EC) = 0;
    *(s16 *)(buf + 0x2EE) = 0;
    p = buf + 8;
    for (l = 0; l < 10; l++) {
        memset(p, 0, 0x4A);
        p += 0x4A;
    }
    *(s32 *)(base + 0x44) = 0;
    *(s32 *)(base + 0x48) = 0;
    *(s32 *)(base + 0x54) = -1;
    *(s32 *)(base + 0x28) = 1;
    *(s32 *)(base + 0x6C) = 0;
    buf = (u8 *)fn_80204768(arg0, fn_803D5870(0xA), 0x20);
    fn_803D5878(base + 0x70, 0, buf, 10);
}