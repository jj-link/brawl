#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_7A130[];

void fn_27_281514(void* p1, void* p2, u32 p3, u32 p4, u32 p5, u32 p6) {
    u8* p = (u8*)p1;
    p[4] = 0;
    *(u32*)(p + 8) = p3;
    *(u32*)(p + 12) = p3;
    *(u32*)(p + 16) = p4;
    *(u16*)(p + 20) = 0;
    *(u16*)(p + 22) = 0;
    *(u32*)p = (u32)lbl_27_data_7A130;
    *(u32*)(p + 24) = (u32)p2;
    *(u32*)(p + 28) = p5;
}
}
