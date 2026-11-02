#include <types.h>
#pragma force_active on

extern "C" {
void OSInitMutex(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), u32, s32);
void __dt__8NtBufferFv(void*);
void fn_8013DB48(void*);
void fn_8014B964(s32, s32, s32);
void fn_8014B96C(s32, s32, s32);
extern unsigned char __vt__8NtBuffer[];
extern unsigned char lbl_8045E794[];
extern unsigned char lbl_8045E7AC[];
extern unsigned char lbl_8045E7C0[];
extern void* lbl_805A0390;
extern s32 lbl_805A0434;
extern const f32 lbl_805A2AC8;
extern const f32 lbl_805A2ACC;
extern const f32 lbl_805A2AD0;
extern const f32 lbl_805A2AD4;
extern const f32 lbl_805A2AD8;
extern const f32 lbl_805A2ADC;
extern const f32 lbl_805A2AE0;
extern const f32 lbl_805A2AE4;
}

struct Byte1D8 {
    u8 a : 1;
    u8 b : 7;
};

struct Word1D8 {
    u32 a : 1;
    u32 b : 8;
    u32 c : 23;
};

struct Word198 {
    u32 a : 8;
    u32 b : 24;
};

extern "C" void* fn_8013D8A8(void* arg0) {
    char* p = (char*)arg0;
    s32 i;

    *(void**)(p + 0x00) = lbl_8045E794;
    *(s32*)(p + 0x04) = 0;
    *(u8*)(p + 0x12) = 0;
    *(u8*)(p + 0x13) = 0x14;
    *(u8*)(p + 0x14) = 0;
    *(u8*)(p + 0x15) = 0;
    *(u8*)(p + 0x16) = 0;
    *(f32*)(p + 0x18) = lbl_805A2AC8;
    *(f32*)(p + 0x1C) = lbl_805A2AC8;
    *(s32*)(p + 0x20) = 0;
    *(void**)(p + 0x38) = __vt__8NtBuffer;
    *(s32*)(p + 0x3C) = 0;
    *(s32*)(p + 0x40) = 0;
    *(u8*)(p + 0x44) = 0;
    *(s32*)(p + 0x48) = 0;
    *(s32*)(p + 0x4C) = 0;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x54) = 0;
    __construct_array(p + 0x58, fn_8013DB48, __dt__8NtBufferFv, 0x14, 4);
    *(s32*)(p + 0xA8) = 0;
    *(u8*)(p + 0xAC) = 1;
    *(s32*)(p + 0x130) = 0;
    *(s32*)(p + 0x134) = 0;
    *(s32*)(p + 0x138) = 0;
    *(s32*)(p + 0x13C) = 0;
    *(u16*)(p + 0x140) = 0xFC18;
    *(s16*)(p + 0x142) = 0;
    *(s16*)(p + 0x144) = 0;
    *(s16*)(p + 0x146) = 0;
    *(s16*)(p + 0x148) = 0;
    *(void**)(p + 0x150) = __vt__8NtBuffer;
    *(s32*)(p + 0x154) = 0;
    *(s32*)(p + 0x158) = 0;
    *(u8*)(p + 0x15C) = 0;
    *(s32*)(p + 0x160) = 0;
    *(s32*)(p + 0x164) = 0;
    *(s32*)(p + 0x16C) = 0;
    *(s32*)(p + 0x170) = 0;
    *(u8*)(p + 0x174) = 0;
    *(s32*)(p + 0x178) = 0;
    *(void**)(p + 0x168) = lbl_8045E7C0;
    OSInitMutex(p + 0x17C);
    ((Byte1D8*)(p + 0x1D8))->a = 0;
    ((Word198*)(p + 0x198))->a = 0;
    ((Word1D8*)(p + 0x1D8))->b = 0;
    *(s32*)(p + 0x194) = 0;
    *(u8*)(p + 0x199) = 0;
    *(u8*)(p + 0x1A5) = 0;
    *(u8*)(p + 0x1A6) = 0;
    *(u8*)(p + 0x1A7) = 0;
    *(u8*)(p + 0x1A8) = 0;
    *(u8*)(p + 0x1A9) = 0;
    *(u8*)(p + 0x1AA) = 0;
    *(u8*)(p + 0x1AB) = 0;
    *(u8*)(p + 0x1AC) = 0;
    *(u8*)(p + 0x1AD) = 0;
    *(s16*)(p + 0x1AE) = 0;
    *(s32*)(p + 0x1B0) = 0;
    *(s32*)(p + 0x1B4) = 0;
    *(s32*)(p + 0x1B8) = 0;
    *(u8*)(p + 0x1BC) = 0;
    *(s16*)(p + 0x1BE) = 0;
    *(s32*)(p + 0x1C0) = 0;
    *(s32*)(p + 0x1C4) = 0;
    *(s32*)(p + 0x1C8) = 0;
    *(s32*)(p + 0x1CC) = 0;
    *(s32*)(p + 0x1D0) = 0;
    *(s32*)(p + 0x1D4) = 0;
    *(u8*)(p + 0x1DA) = 0;
    *(s32*)(p + 0x1DC) = 0;
    *(s32*)(p + 0x1E0) = 0;
    *(s16*)(p + 0x1E4) = 0;
    *(s32*)(p + 0x1E8) = 0;
    *(s32*)(p + 0x1EC) = 0;
    *(s32*)(p + 0x1F0) = 0;
    *(f32*)(p + 0x1F4) = lbl_805A2AC8;
    *(f32*)(p + 0x1F8) = lbl_805A2AC8;
    *(f32*)(p + 0x1FC) = lbl_805A2AC8;
    *(f32*)(p + 0x200) = lbl_805A2ACC;
    *(f32*)(p + 0x204) = lbl_805A2AD0;
    *(f32*)(p + 0x208) = lbl_805A2AC8;
    *(f32*)(p + 0x20C) = lbl_805A2AC8;
    *(f32*)(p + 0x210) = lbl_805A2AC8;
    *(f32*)(p + 0x214) = lbl_805A2AC8;
    *(f32*)(p + 0x218) = lbl_805A2AC8;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(u8*)(p + 0x238) = 0;
    *(s32*)(p + 0x23C) = 0;
    *(void**)(p + 0x22C) = lbl_8045E7AC;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24C) = 0;
    *(s32*)(p + 0x450) = 0;
    *(s32*)(p + 0x454) = 0;
    *(s32*)(p + 0x458) = 0;
    lbl_805A0390 = arg0;
    *(f32*)(p + 0x210) = lbl_805A2AD4;
    *(f32*)(p + 0x214) = lbl_805A2AD8;
    *(f32*)(p + 0x218) = lbl_805A2ADC;
    *(f32*)(p + 0x21C) = lbl_805A2AD8;
    *(f32*)(p + 0x220) = lbl_805A2AE0;
    *(f32*)(p + 0x224) = lbl_805A2AE4;
    *(f32*)(p + 0x228) = lbl_805A2ACC;

    i = 0;
    do {
        fn_8014B964(lbl_805A0434, i, 0);
        fn_8014B96C(lbl_805A0434, i, 0);
        i++;
    } while (i < 6);

    return arg0;
}
