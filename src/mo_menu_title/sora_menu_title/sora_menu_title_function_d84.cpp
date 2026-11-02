#pragma force_active on
#include <types.h>

extern "C" {
void fn_8018E808(void*);
void exit__6gfTaskFv(void*);
void fn_800B8A0C(void*, s32);
}

struct ObjPad {
    u8 pad[0x5C];
};

struct VObj : ObjPad {
    virtual void vfn0(s32);
    virtual void vfn1(s32);
    virtual void vfn2(s32);
};

extern "C" void fn_24_D84(void* self) {
    u8* p = (u8*)self;
    fn_8018E808(p + 0x40);
    exit__6gfTaskFv(*(void**)(p + 0x44));
    VObj* obj = *(VObj**)(p + 0x48);
    *(void**)(p + 0x44) = 0;
    if (obj != 0) {
        obj->vfn0(1);
    }
    VObj* obj2 = *(VObj**)(p + 0x4C);
    *(void**)(p + 0x48) = 0;
    if (obj2 != 0) {
        obj2->vfn0(1);
    }
    *(void**)(p + 0x4C) = 0;
    fn_800B8A0C(*(void**)(p + 0x50), 1);
    *(void**)(p + 0x50) = 0;
}
