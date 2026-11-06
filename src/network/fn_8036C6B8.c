#include <types.h>
#pragma force_active on

extern void fn_80372DD8(char *, const char *, unsigned long);

void fn_8036C6B8(void *arg0, void *arg1) {
    u8 *src = (u8 *)arg0;
    u8 *dst = (u8 *)arg1;
    void *t;
    u8 *p;

    t = *(void **)(src + 0x00);
    if (t != NULL) {
        fn_80372DD8((char *)(dst + 0x08), (const char *)t, 0x1F);
    } else {
        dst[0x08] = 0;
    }
    t = *(void **)(src + 0x04);
    if (t != NULL) {
        fn_80372DD8((char *)(dst + 0x27), (const char *)t, 0x15);
    } else {
        dst[0x27] = 0;
    }
    t = *(void **)(src + 0x08);
    if (t != NULL) {
        fn_80372DD8((char *)(dst + 0x3C), (const char *)t, 0x33);
    } else {
        dst[0x3C] = 0;
    }
    t = *(void **)(src + 0x0C);
    if (t != NULL) {
        fn_80372DD8((char *)(dst + 0x6F), (const char *)t, 0x1F);
    } else {
        dst[0x6F] = 0;
    }
    t = *(void **)(src + 0x10);
    if (t != NULL) {
        fn_80372DD8((char *)(dst + 0x8E), (const char *)t, 0x1F);
    } else {
        dst[0x8E] = 0;
    }
    t = *(void **)(src + 0x14);
    if (t != NULL) {
        fn_80372DD8((char *)(dst + 0xAD), (const char *)t, 0x4C);
    } else {
        dst[0xAD] = 0;
    }
    *(u32 *)(dst + 0xFC) = *(u32 *)(src + 0x18);
    fn_80372DD8((char *)(dst + 0x100), (const char *)(src + 0x1C), 0x0B);
    fn_80372DD8((char *)(dst + 0x10B), (const char *)(src + 0x27), 0x03);
    *(f32 *)(dst + 0x110) = *(f32 *)(src + 0x2C);
    *(f32 *)(dst + 0x114) = *(f32 *)(src + 0x30);
    p = src + 0x34;
    if (p != NULL) {
        fn_80372DD8((char *)(dst + 0x118), (const char *)p, 0x80);
    } else {
        dst[0x118] = 0;
    }
    *(u32 *)(dst + 0x198) = *(u32 *)(src + 0xB4);
    *(u32 *)(dst + 0x19C) = *(u32 *)(src + 0xB8);
    *(u32 *)(dst + 0x1A0) = *(u32 *)(src + 0xBC);
    *(u32 *)(dst + 0x1A4) = *(u32 *)(src + 0xC0);
    *(u32 *)(dst + 0x1A8) = *(u32 *)(src + 0xC4);
    t = *(void **)(src + 0xC8);
    if (t != NULL) {
        fn_80372DD8((char *)(dst + 0x1AC), (const char *)t, 0x33);
    } else {
        dst[0x1AC] = 0;
    }
    *(u32 *)(dst + 0xFC) = *(u32 *)(src + 0x18);
    *(f32 *)(dst + 0x110) = *(f32 *)(src + 0x2C);
    *(f32 *)(dst + 0x114) = *(f32 *)(src + 0x30);
    *(u32 *)(dst + 0x198) = *(u32 *)(src + 0xB4);
    *(u32 *)(dst + 0x19C) = *(u32 *)(src + 0xB8);
    *(u32 *)(dst + 0x1A0) = *(u32 *)(src + 0xBC);
    *(u32 *)(dst + 0x1A4) = *(u32 *)(src + 0xC0);
    *(u32 *)(dst + 0x1A8) = *(u32 *)(src + 0xC4);
    *(u32 *)(dst + 0x1E0) = *(u32 *)(src + 0xCC);
    *(u32 *)(dst + 0x1E4) = *(u32 *)(src + 0xD0);
    *(u32 *)(dst + 0x1E8) = *(u32 *)(src + 0xD4);
    *(u32 *)(dst + 0x1EC) = *(u32 *)(src + 0xD8);
    *(u32 *)(dst + 0x1F0) = *(u32 *)(src + 0xDC);
    *(u32 *)(dst + 0x1F4) = *(u32 *)(src + 0xE0);
    *(u32 *)(dst + 0x1F8) = *(u32 *)(src + 0xE4);
    *(u32 *)(dst + 0x1FC) = *(u32 *)(src + 0xE8);
    *(u32 *)(dst + 0x200) = *(u32 *)(src + 0xEC);
}
