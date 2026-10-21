#include <types.h>
#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);

extern "C" void fn_74_4AAC(u8* self) {
    u8* p = self + 0xd0;
    if (p == 0) return;

    u8* a = *(u8**)(self + 0x44);
    u8* m = *(u8**)a;
    if (m == 0) return;

    if (*(u32*)(m + 0x11c) == 0) {
        *(u32*)(p + 0xc) = 0;
        *(u32*)(*(u32**)(p + 4)) = 0;
        *(u8**)(m + 0x11c) = p;
        EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
        *(u16*)(m + 0x122) = (u16)**(u32**)(p + 4);
    }

    u8* q = *(u8**)(self + 0x158);
    float f = *(float*)(q + 4);
    f = *(u8*)(q + 0x23) ? f : -f;

    *(float*)(*(u8**)(p + 4) + 0x34) = *(float*)q;
    *(float*)(*(u8**)(p + 4) + 0x40) = f;
}
