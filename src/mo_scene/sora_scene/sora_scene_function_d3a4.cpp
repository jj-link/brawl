#pragma force_active on
#include <types.h>

extern "C" {
void* fn_800B03F0(void* self, s32 id);
void* fn_80015DB4(void* a, s32 b, s32 c, s32 d, u16 e);
void fn_10_0(void* args);
}

struct SceneArgs {
    void* p00;
    void* p04;
    void* p08;
    s32 p0c;
    s32 p10;
    void* p14;
    void* p18;
    void* p1c;
    void* p20;
    void* p24;
    s32 p28;
    void* p2c;
    void* p30;
    s32 p34;
    s32 p38;
    s32 p3c;
    u8 p40;
};

extern "C" void fn_1_D3A4(void* self) {
    SceneArgs a;
    u8* p = (u8*)self;

    a.p00 = 0;
    a.p04 = 0;
    a.p08 = 0;
    a.p10 = 0;
    a.p14 = 0;
    a.p18 = 0;
    a.p1c = 0;
    a.p20 = 0;
    a.p24 = 0;
    a.p28 = 0;
    a.p2c = 0;
    a.p30 = 0;
    a.p34 = 0;
    a.p38 = 0;
    a.p3c = 0;
    a.p40 = 0;

    *(void**)(p + 0x38c) = fn_800B03F0(*(void**)(p + 0x410), 0x1e);
    *(void**)(p + 0x390) = fn_800B03F0(*(void**)(p + 0x410), 0x46);
    *(void**)(p + 0x394) = fn_800B03F0(*(void**)(p + 0x410), 0x50);
    *(void**)(p + 0x398) = fn_800B03F0(*(void**)(p + 0x410), 0x28);
    *(void**)(p + 0x39c) = fn_800B03F0(*(void**)(p + 0x410), 0x5a);
    *(void**)(p + 0x3a0) = fn_800B03F0(*(void**)(p + 0x410), 0x32);
    *(void**)(p + 0x3a4) = fn_800B03F0(*(void**)(p + 0x410), 0x3c);
    *(void**)(p + 0x3a8) = fn_800B03F0(*(void**)(p + 0x410), 0x82);
    *(void**)(p + 0x3b4) = fn_80015DB4(*(void**)(p + 0x410), 0, 1, 0x6e, (u16)0xfffe);
    *(void**)(p + 0x3b8) = fn_80015DB4(*(void**)(p + 0x410), 0, 1, 0x78, (u16)0xfffe);

    a.p00 = p + 0x38c;
    a.p04 = p + 0x390;
    a.p08 = p + 0x394;
    a.p0c = *(s32*)(p + 0x3b0);
    a.p14 = p + 0x398;
    a.p18 = p + 0x39c;
    a.p1c = p + 0x3a0;
    a.p20 = p + 0x3a4;
    a.p24 = p + 0x3a8;
    a.p10 = *(s32*)(p + 0x3ac);
    a.p28 = *(s32*)(*(s32*)(p + 0x35c) + 0x48);
    a.p2c = *(void**)(p + 0x3b4);
    a.p30 = *(void**)(p + 0x3b8);
    a.p3c = 0xa8c;
    a.p34 = 0x27;
    a.p38 = 0x27;
    a.p40 = *(u8*)(p + 0x408);
    fn_10_0(&a);
}
