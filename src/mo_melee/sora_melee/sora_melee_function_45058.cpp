#include <types.h>
#pragma force_active on

struct fn_27_45058_Inner {
    virtual void unused0();
    virtual void* vf0(u32 index);
    virtual void* vf1();
    virtual void* vf2();
    virtual void* vf3();
};

struct fn_27_45058_Obj {
    u8 pad[0x58];
    fn_27_45058_Inner* m_inner;
};

extern "C" void fn_27_4290C(void* self, u32 index);

extern "C" {
void fn_27_45058(fn_27_45058_Obj* self, u32 index, u32 arg);
}

extern "C" void fn_27_45058(fn_27_45058_Obj* self, u32 index, u32 arg) {
    fn_27_4290C(self->m_inner->vf0(arg), index);
}
