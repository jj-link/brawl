#include <types.h>
#pragma force_active on

struct Ret {
    u8 pad[0x5c];
    u32 m_5c;
};

struct Obj {
    virtual void f0();
    virtual Ret* f1(s32 idx);
};

struct Self {
    u8 pad[4];
    s16 m_4;
};

extern "C" void fn_27_46FE0(Self* self, Obj* obj, s32 idx, u32 val) {
    Ret* r = obj->f1(self->m_4 + idx);
    r->m_5c = val;
}
