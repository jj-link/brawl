#pragma force_active on
#include <types.h>

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);

extern const float lbl_71_rodata_238;

struct CallbackOwner {
    u8 pad[4];
    void* p;  // +0x04
    u32 f2;   // +0x08
    u32 f;    // +0x0c
};

extern "C" void fn_71_E96C(void* self) {
    u8* p = (u8*)self;
    CallbackOwner* st = (CallbackOwner*)((u32)self + 0xd0);
    if ((u32)st == 0)
        return;
    void* model = (*(void***)(p + 0x44))[0];
    if (model == 0)
        return;
    if (*(u32*)((u8*)model + 0x11c) == 0) {
        st->f = 0;
        *(u32*)st->p = *(u32*)(p + 0xc4);
        *(u32*)((u8*)model + 0x11c) = (u32)st;
        EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
        *(u16*)((u8*)model + 0x122) = (u16)*(u32*)st->p;
    }
    ((float*)st->p)[2] = *(float*)(p + 0x164);
    ((float*)st->p)[3] = lbl_71_rodata_238;
    ((float*)st->p)[4] = lbl_71_rodata_238;
    ((float*)st->p)[7] = **(float**)(p + 0x160);
}
