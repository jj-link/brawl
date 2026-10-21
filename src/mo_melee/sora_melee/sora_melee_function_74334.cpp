#include <types.h>
#pragma force_active on

class Iface {
public:
    virtual void v0();
    virtual void* v1(s32 idx);
    virtual void v2();
    virtual s32 v3();
};

class Child {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual u32 v11(s32 arg, f32 a, f32 b);
};

struct Owner {
    u8 pad0[0x30];
    Iface* m_iface;
    s32 m_index;
};

extern "C" s32 fn_27_74334(Owner* self, s32 arg1, f32 farg1, f32 farg2) {
    s32 idx = self->m_index;
    if (idx >= 0) {
        if (idx < self->m_iface->v3()) {
            void* node = self->m_iface->v1(idx);
            Child* child = *(Child**)node;
            if (child != 0) {
                if (child->v11(arg1, farg1, farg2) == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
