#include <types.h>
#include <ft/ft_manager.h>
#pragma force_active on

extern "C" {
void* fn_27_241E30(void* self, const char* name);
float fn_27_10AD0C(ftManager* mgr);
extern u8 lbl_27_bss_59D8;
extern char lbl_27_data_52F90[];
extern const f32 lbl_27_rodata_4140;
extern const f32 lbl_27_rodata_4144;

void* fn_27_255808(void* self, const char* name) {
    u8* p = (u8*)self;
    fn_27_241E30(self, name);
    *(char**)(p + 0x3C) = lbl_27_data_52F90;
    p[0xBB] = 0;
    p[0xBC] = 1;
    *(s32*)(p + 0xC0) = 0;
    p[0xC4] = 0;
    *(s32*)(p + 0xC8) = 0xFF;
    *(s32*)(p + 0xCC) = 0xFF;
    p[0x10C] = 0;
    *(f32*)(p + 0x110) = lbl_27_rodata_4140;
    *(s32*)(p + 0x114) = -1;
    p[0x119] = 0;
    lbl_27_bss_59D8 = 1;
    *(s32*)(p + 0x48) = 0;
    p[0x64] = 0;
    p[0x6B] = 0;
    p[0x72] = 0;
    *(s32*)(p + 0x7C) = 0;
    *(f32*)(p + 0x98) = lbl_27_rodata_4144;
    p[0xB4] = 0;
    *(s32*)(p + 0x4C) = 0;
    p[0x65] = 0;
    p[0x6C] = 0;
    p[0x73] = 0;
    *(s32*)(p + 0x80) = 0;
    *(f32*)(p + 0x9C) = lbl_27_rodata_4144;
    p[0xB5] = 0;
    *(s32*)(p + 0x50) = 0;
    p[0x66] = 0;
    p[0x6D] = 0;
    p[0x74] = 0;
    *(s32*)(p + 0x84) = 0;
    *(f32*)(p + 0xA0) = lbl_27_rodata_4144;
    p[0xB6] = 0;
    *(s32*)(p + 0x54) = 0;
    p[0x67] = 0;
    p[0x6E] = 0;
    p[0x75] = 0;
    *(s32*)(p + 0x88) = 0;
    *(f32*)(p + 0xA4) = lbl_27_rodata_4144;
    p[0xB7] = 0;
    *(s32*)(p + 0x58) = 0;
    p[0x68] = 0;
    p[0x6F] = 0;
    p[0x76] = 0;
    *(s32*)(p + 0x8C) = 0;
    *(f32*)(p + 0xA8) = lbl_27_rodata_4144;
    p[0xB8] = 0;
    *(s32*)(p + 0x5C) = 0;
    p[0x69] = 0;
    p[0x70] = 0;
    p[0x77] = 0;
    *(s32*)(p + 0x90) = 0;
    *(f32*)(p + 0xAC) = lbl_27_rodata_4144;
    p[0xB9] = 0;
    *(s32*)(p + 0x60) = 0;
    p[0x6A] = 0;
    p[0x71] = 0;
    p[0x78] = 0;
    *(s32*)(p + 0x94) = 0;
    *(f32*)(p + 0xB0) = lbl_27_rodata_4144;
    p[0xBA] = 0;
    *(s32*)(p + 0xEC) = -1;
    *(s32*)(p + 0xF0) = -1;
    *(s32*)(p + 0xF4) = -1;
    *(s32*)(p + 0xF8) = -1;
    *(s32*)(p + 0xFC) = -1;
    *(s32*)(p + 0x100) = -1;
    *(s32*)(p + 0x104) = -1;
    *(s32*)(p + 0x108) = -1;
    if (g_ftManager != 0) {
        *(f32*)(p + 0x110) = fn_27_10AD0C(g_ftManager);
    }
    {
        s32 v = 0;
        u32 t = ((u32)(*(u8*)(*(u8**)(p + 0x44) + 8)) >> 2) & 0x3F;
        if (t != 9 && t != 0x12) {
            v = 1;
        }
        p[0x118] = (u8)v;
    }
    return self;
}
}
