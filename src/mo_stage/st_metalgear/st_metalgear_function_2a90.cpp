#pragma force_active on
#include <types.h>

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);

struct CallbackOwner {
    u8 pad[4];
    u32* data;
    u32 unk8;
    u32 unkC;
};

extern "C" void fn_71_2A90(void* self) {
    u8* p = (u8*)self;
    CallbackOwner* st = (CallbackOwner*)(p + 0xD0);

    if (st == 0)
        return;

    void* model = (*(void***)(p + 0x44))[*(u32*)(p + 0xC0)];
    if (model == 0)
        return;

    if (*(u32*)((u8*)model + 0x11C) == 0) {
        st->unkC = 0;
        *st->data = *(u32*)(p + 0xC4);
        *(u32*)((u8*)model + 0x11C) = (u32)st;
        EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
        *(u16*)((u8*)model + 0x122) = (u16)*st->data;
    }

    float* dst = (float*)st->data;
    float* src = *(float**)(p + 0x158);
    dst[2] = src[0];
    dst[3] = src[1];
    dst[4] = src[2];
}
