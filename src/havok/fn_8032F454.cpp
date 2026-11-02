#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern unsigned char lbl_80414F78[];
extern unsigned char lbl_80415150[];
extern unsigned char lbl_805335A0[];
extern unsigned char lbl_805335C4[];

void fn_8032F454(void) {
    unsigned char* sp8;
    s32 spC;
    s32 sp10;

    sp8 = lbl_80414F78 + 0xB0;
    spC = 2;
    sp10 = 0;
    fn_8027C808(lbl_805335A0, lbl_80415150, 0, 0xC, 0, 0, 0, 0, (u32)sp8, (u32)spC, (u32)sp10);
    sp8 = lbl_80414F78 + 0x138;
    spC = 8;
    sp10 = 0;
    fn_8027C808(lbl_805335C4, lbl_80415150 + 0x18, 0, 0x60, 0, 0, (u32)(lbl_80414F78 + 0x94), 1, (u32)sp8, (u32)spC, (u32)sp10);
}
}

__declspec(section ".ctors") extern void* const fn_8032F454_ctor = (void*)fn_8032F454;
