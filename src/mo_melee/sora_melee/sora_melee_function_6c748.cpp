#include <types.h>
#pragma force_active on

class VObj {
public:
    virtual void v0();
    virtual u32 v1();
    virtual void v2();
    virtual void v3();
};

extern "C" u32 fn_27_6F30C(void*);

extern "C" void fn_27_6C748(void* self) {
    VObj* p = (VObj*)*(u32*)((u8*)self + 0x48);
    u32 o = (u32)p->v1();

    o = fn_27_6F30C((void*)(o + 0x1c));
    o = *(u32*)(o + 0x44);
    o = *(u32*)(o + 0xd8);
    o = *(u32*)(o + 0x14);

    ((VObj*)o)->v3();
}
