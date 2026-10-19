#include <types.h>
#pragma force_active on

struct fnResult {
    s32 m_a;
    s32 m_b;
};

class fnSubObj {
public:
    virtual void f0();
    virtual fnResult* f1();
};

class fnOwner {
public:
    s32 m_pad[4];
    fnSubObj m_sub;
};

extern "C" {
    s32 fn_27_F5204(fnOwner* self) {
        fnSubObj* p = &self->m_sub;
        return p->f1()->m_b;
    }
}
