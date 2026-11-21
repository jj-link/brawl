#include <types.h>
#pragma force_active on

extern "C" void fn_41_1BEA8(void* dst, const void* src);
extern "C" void fn_41_329FC(void* self, int index);
extern "C" void stop__18gfGameFrameCounterFv(void*);
extern "C" void start__18gfGameFrameCounterFv(void*);
extern "C" extern float lbl_41_rodata_E28;

extern "C" s32 fn_41_30788(u8* p, void* a1, const u8* s2) {
    const u8* s1 = (const u8*)a1;

    p[0x21b9] = 0;
    p[0x21b8] = 0;
    p[0x2215] = 0;
    p[0x2216] = 0;
    p[0x2217] = 0;
    p[0x2218] = 0;
    p[0x2219] = 0;
    p[0x221a] = 0;
    p[0x221b] = 0;

    *(u32*)(p + 0x21cc) = *(u32*)(s1 + 0x0c);
    *(u32*)(p + 0x21d0) = *(u32*)(s1 + 0x10);
    *(f32*)(p + 0x21d4) = (f32)*(u32*)(s1 + 0x00);
    *(f32*)(p + 0x21d8) = (f32)*(u32*)(s1 + 0x00);
    *(u32*)(p + 0x21dc) = *(u32*)(s1 + 0x08);
    *(s32*)(p + 0x21e8) = -1;
    *(s32*)(p + 0x21ec) = 0;
    p[0x21ba] = s1[0x24];
    p[0x21bb] = s1[0x25];
    p[0x21b6] = s1[0x26];
    p[0x21b7] = s1[0x27];
    *(u32*)(p + 0x21bc) = 0;
    *(u32*)(p + 0x21c0) = 0;
    *(u32*)(p + 0x21c4) = 0;
    *(u32*)(p + 0x21c8) = 0;
    *(u32*)(p + 0x2208) = 0;
    *(u32*)(p + 0x2234) = 0;
    p[0x21b5] = s2[0x02];

    fn_41_1BEA8(p + 0x21f0, s2 + 0x14);
    fn_41_1BEA8(p + 0x21f8, p + 0x21f0);
    fn_41_1BEA8(p + 0x2200, s2 + 0x1c);

    *(f32*)(p + 0x2204) = *(f32*)(p + 0x2204) + *(f32*)(s1 + 0x5c);

    fn_41_329FC(p, 0);
    stop__18gfGameFrameCounterFv(p + 0x221c);
    if (*(s32*)(p + 0x21d0) > 0) {
        p[0x21b9] = 1;
        start__18gfGameFrameCounterFv(p + 0x221c);
    }
    if (*(f32*)(p + 0x21d8) > lbl_41_rodata_E28) {
        p[0x21b8] = 1;
    }
    {
        s32 t = *(s32*)(s2 + 0x24);
        if (t != 0) {
            *(s32*)(p + 0x2234) = t;
        }
    }
    return 1;
}
