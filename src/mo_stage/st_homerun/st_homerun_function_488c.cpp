#pragma force_active on
#include <types.h>

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
extern "C" const float lbl_88_rodata_E8[];

struct V3 {
    float x, y, z;
};

extern "C" void fn_88_488C(u8* self) {
    const float* r = lbl_88_rodata_E8;
    u8* p = self + 0xD0;
    if (p != 0) {
        u8* a = *(u8**)(self + 0x44);
        u8* m = *(u8**)a;
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                *(u32*)(*(u8**)(p + 4)) = *(u32*)(self + 0xc4);
                *(u32*)(*(u8**)(p + 4) + 0x80) = *(u32*)(self + 0x188);
                *(u32*)(*(u8**)(p + 4) + 0x100) = *(u32*)(self + 0x18c);
                *(u32*)(*(u8**)(p + 4) + 0x180) = *(u32*)(self + 0x190);
                *(u8**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                *(u16*)(m + 0x122) = (u16)*(u32*)(*(u8**)(p + 4));
            }
            V3 v = {r[0], r[1], r[2]};
            u8* q = *(u8**)(p + 4);
            *(float*)(q + 0x8) = *(float*)(self + 0x15c);
            *(float*)(q + 0xc) = *(float*)(self + 0x160);
            *(float*)(q + 0x10) = *(float*)(self + 0x164);
            q = *(u8**)(p + 4);
            *(float*)(q + 0xac) = v.x;
            *(float*)(q + 0xb0) = v.y;
            *(float*)(q + 0xb4) = v.z;
            q = *(u8**)(p + 4);
            *(float*)(q + 0x12c) = v.x;
            *(float*)(q + 0x130) = v.y;
            *(float*)(q + 0x134) = v.z;
            q = *(u8**)(p + 4);
            *(float*)(q + 0x1ac) = v.x;
            *(float*)(q + 0x1b0) = v.y;
            *(float*)(q + 0x1b4) = v.z;
        }
    }
}
