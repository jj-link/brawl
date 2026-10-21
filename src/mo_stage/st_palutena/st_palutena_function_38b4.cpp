#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(u32 size, int heap);
extern "C" void bind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdlP16gfModelAnimation(void* mdl, void* anim);

extern "C" {
void fn_67_38B4(u8* self, u32* src) {
    u8* obj = *(u8**)(self + 0x44);
    u8* mdl = *(u8**)obj;
    if (mdl != nullptr) {
        u8* p = (u8*)__nw__FUlQ25Heaps8HeapType(0x20, 0xf);
        if (p != nullptr) {
            *(u32*)(p + 0x0) = *src;
            p[0x4] = 1;
            *(u32*)(p + 0x8) = 0;
            *(u32*)(p + 0xc) = 0;
            *(u32*)(p + 0x10) = 0;
            *(u32*)(p + 0x14) = 0;
            *(u32*)(p + 0x18) = 0;
            *(u32*)(p + 0x1c) = 0;
        }
        *(u8**)(self + 0x1a4) = p;
        if (p != nullptr) {
            p[0x4] = 0;
            bind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdlP16gfModelAnimation(mdl, *(void**)(self + 0x1a4));
        }
    }
}
}
