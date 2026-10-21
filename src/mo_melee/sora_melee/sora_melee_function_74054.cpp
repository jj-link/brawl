#include <types.h>
#pragma force_active on

class fn27C {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7(s32 arg) = 0;
};

class fn27B {
public:
    fn27C* m_c;
};

class fn27A {
public:
    virtual void v0() = 0;
    virtual fn27B* v1(s32 idx) = 0;
    virtual void v2() = 0;
    virtual s32 v3() = 0;
};

class fn27Ctx {
public:
    u8 pad0[0x30];
    fn27A* m_a;
    s32 m_idx;
    u8 pad1[0x7D - 0x38];
    u8 m_state;
};

extern "C" {
void fn_27_74054(fn27Ctx* self, s32 arg) {
    if (self->m_state == 1) {
        s32 idx = self->m_idx;
        if (idx >= 0) {
            if (idx < self->m_a->v3()) {
                fn27C* c = self->m_a->v1(idx)->m_c;
                if (c != nullptr) {
                    c->v7(arg);
                }
            }
        }
    }
}
}
