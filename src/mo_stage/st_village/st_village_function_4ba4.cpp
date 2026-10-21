#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void bind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdlP16gfModelAnimation(void* mdl, void* anim);

extern "C" {
void fn_70_4BA4(u8* self, u32* arg) {
    u32* src = *(u32**)(*(u8**)(self + 0x44));
    void* mdl = *(void**)(*(u8**)(self + 0x44));
    if (mdl != nullptr) {
        u8* obj = (u8*)__nw__FUlQ25Heaps8HeapType(0x20, 0xf);
        if (obj != nullptr) {
            *(u32*)(obj + 0x0) = *arg;
            *(u8*)(obj + 0x4) = 1;
            *(u32*)(obj + 0x8) = 0;
            *(u32*)(obj + 0xc) = 0;
            *(u32*)(obj + 0x10) = 0;
            *(u32*)(obj + 0x14) = 0;
            *(u32*)(obj + 0x18) = 0;
            *(u32*)(obj + 0x1c) = 0;
        }
        *(u8**)(self + 0x1c8) = obj;
        if (obj != nullptr) {
            *(u8*)(obj + 0x4) = 0;
            bind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdlP16gfModelAnimation(mdl, *(void**)(self + 0x1c8));
        }
    }
}
}
