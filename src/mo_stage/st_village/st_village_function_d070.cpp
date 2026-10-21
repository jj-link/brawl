#pragma force_active on
#include <types.h>

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);

extern "C" void fn_70_D070(void* self) {
    u8* s = (u8*)self;
    u8* p = s + 0xD0;
    if (p != 0) {
        u8* a = *(u8**)(s + 0x44);
        u8* m = *(u8**)a;
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                *(u32*)(*(u32**)(p + 4)) = *(u32*)(s + 0x180);
                *(u32*)((u8*)(*(u32**)(p + 4)) + 0x80) = *(u32*)(s + 0x184);
                *(u8**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                *(u16*)(m + 0x122) = (u16)*(u32*)(*(u32**)(p + 4));
            }
            u8* q1 = *(u8**)(p + 4);
            *(float*)(q1 + 0x38) = *(float*)(s + 0x168);
            *(float*)(q1 + 0x3c) = *(float*)(s + 0x16c);
            *(float*)(q1 + 0x40) = *(float*)(s + 0x170);
            u8* q2 = *(u8**)(p + 4);
            *(float*)(q2 + 0xb8) = *(float*)(s + 0x174);
            *(float*)(q2 + 0xbc) = *(float*)(s + 0x178);
            *(float*)(q2 + 0xc0) = *(float*)(s + 0x17c);
        }
    }
}
