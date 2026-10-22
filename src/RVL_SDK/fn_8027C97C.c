#include <types.h>
#pragma force_active on

extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern unsigned char lbl_8040EB70[];
extern unsigned char lbl_8040EB98[];
extern unsigned char lbl_8040EBC0[];
extern unsigned char lbl_805323A0[];
extern unsigned char lbl_805323C4[];

void fn_8027C97C(void) {
    unsigned char* sp8;
    s32 spC;
    s32 sp10;

    sp8 = lbl_8040EB70;
    spC = 2;
    sp10 = 0;
    fn_8027C808(lbl_805323A0, lbl_8040EBC0, 0, 8, 0, 0, 0, 0, (u32)sp8, (u32)spC, (u32)sp10);
    sp8 = lbl_8040EB98;
    spC = 2;
    sp10 = 0;
    fn_8027C808(lbl_805323C4, lbl_8040EBC0 + 0x10, 0, 0xC, 0, 0, 0, 0, (u32)sp8, (u32)spC, (u32)sp10);
}

__declspec(section ".ctors") extern void* const fn_8027C97C_ctor = (void*)fn_8027C97C;
