#include <types.h>
#pragma force_active on

extern "C" void fn_801BF13C(void* p, float scale);
extern "C" void fn_801C0AB0(void* p);
extern "C" const float lbl_805A34B8;
extern "C" const float lbl_805A34BC;
extern "C" const float lbl_805A34E0;

extern "C" void fn_801BD9E8(u8* self, s32 arg1, s32 arg2) {
    *(s32*)(self + 0xE0) = 0;
    *(s32*)(self + 0xD4) = arg1;
    *(s32*)(self + 0xD8) = arg2;
    *(u8*)(self + 0x31) = 0;
    *(u8*)(self + 0x34) = 1;
    *(u8*)(self + 0x35) = 0;
    *(s32*)(self + 0xC8) = 0;
    *(s32*)(self + 0xC0) = 0x3C;
    *(s32*)(self + 0xC4) = 0x3C;
    *(f32*)(self + 0xA8) = lbl_805A34BC;
    *(f32*)(self + 0xAC) = lbl_805A34B8;
    *(f32*)(self + 0xB0) = lbl_805A34B8;
    *(f32*)(self + 0xB4) = lbl_805A34BC;
    *(f32*)(self + 0x38) = lbl_805A34BC;
    *(f32*)(self + 0x98) = lbl_805A34B8;
    *(f32*)(self + 0x3C) = lbl_805A34BC;
    *(f32*)(self + 0x40) = lbl_805A34B8;
    *(f32*)(self + 0x44) = lbl_805A34B8;
    *(f32*)(self + 0x48) = lbl_805A34B8;
    *(s32*)(self + 0x4C) = 0;
    *(s32*)(self + 0x50) = 1;
    *(f32*)(self + 0x54) = lbl_805A34BC;
    *(f32*)(self + 0x58) = lbl_805A34B8;
    *(f32*)(self + 0x5C) = lbl_805A34B8;
    *(f32*)(self + 0x60) = lbl_805A34B8;
    *(f32*)(self + 0x64) = lbl_805A34B8;
    *(f32*)(self + 0x68) = lbl_805A34BC;
    *(f32*)(self + 0x78) = lbl_805A34B8;
    *(f32*)(self + 0x88) = lbl_805A34B8;
    *(f32*)(self + 0x6C) = lbl_805A34BC;
    *(f32*)(self + 0x7C) = lbl_805A34B8;
    *(f32*)(self + 0x8C) = lbl_805A34B8;
    *(f32*)(self + 0x70) = lbl_805A34BC;
    *(f32*)(self + 0x80) = lbl_805A34B8;
    *(f32*)(self + 0x90) = lbl_805A34B8;
    *(f32*)(self + 0x74) = lbl_805A34BC;
    *(f32*)(self + 0x84) = lbl_805A34B8;
    *(f32*)(self + 0x94) = lbl_805A34B8;
    *(u8*)(self + 0xB8) = 0xFF;
    *(u8*)(self + 0xB9) = 0xFF;
    *(u16*)(self + 0xBA) = 0;
    *(u16*)(self + 0xBC) = 0;
    *(f32*)(self + 0x9C) = lbl_805A34B8;
    *(s32*)(self + 0xA4) = 0;
    *(s32*)(self + 0xA0) = 0;
    fn_801BF13C(self, lbl_805A34E0);
    fn_801C0AB0(self + 0x18);
    *(u8*)(self + 0x30) = 0;
    *(s32*)(self + 0xCC) = 0;
    *(s32*)(self + 0xD0) = 0;
}
