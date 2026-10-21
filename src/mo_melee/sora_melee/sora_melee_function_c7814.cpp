#include <types.h>
#pragma force_active on

struct SubObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();

    SubObj* m_sub;      // 0x04
    s32 m_count;        // 0x08
    s32 m_timer;        // 0x0C
};

extern "C" void fn_27_C7814(Obj* self) {
    if (self->v4() == 0) {
        if (self->m_timer > 0) {
            self->m_timer--;
            if (self->m_timer <= 0) {
                self->m_count = 0;
            } else {
                self->m_count += 4;
            }
        } else if (self->m_sub != 0) {
            self->m_sub->v6();
        }
    }
}
