#pragma force_active on
#include <types.h>

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);

struct CallbackOwner {
    u8 pad[4];
    void* p;
    u32 f2;
    u32 f;
};

extern "C" void fn_71_2D90(void* self) {
    u8* p = (u8*)self;
    CallbackOwner* st = (CallbackOwner*)((u32)self + 0xd0);
    if ((u32)st == 0)
        return;
    void* model = (*(void***)(p + 0x44))[*(u32*)(p + 0xc0)];
    if (model == 0)
        return;
    if (*(u32*)((u8*)model + 0x11c) == 0) {
        st->f = 0;
        *(u32*)st->p = *(u32*)(p + 0xc4);
        *(u32*)((u8*)model + 0x11c) = (u32)st;
        EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
        *(u16*)((u8*)model + 0x122) = (u16)*(u32*)st->p;
    }
    {
        float* fp = (float*)st->p;
        fp[2] = *(float*)(p + 0x160);
        fp[3] = *(float*)(p + 0x164);
        fp[4] = *(float*)(p + 0x168);
    }
    {
        float* fp = (float*)st->p;
        fp[5] = *(float*)(p + 0x16c);
        fp[6] = *(float*)(p + 0x170);
        fp[7] = *(float*)(p + 0x174);
    }
}
