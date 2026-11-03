#pragma force_active on

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

extern void *fn_8022EE58(u16 size);
extern void fn_80232034(u8 *dst, const u8 *src);
extern void fn_802324E0(void *arg);

void fn_80234204(const u8 *src, int a1, int a2, int a3, s8 arg4) {
    u8 *p = fn_8022EE58(0x12);
    if (p != 0) {
        fn_80232034(p + 0xB, src);
        *(s8 *)(p + 0xA) = arg4;
        *(s16 *)p = 0x105;
        fn_802324E0(p);
    }
}
