#include <types.h>
#pragma force_active on

struct Plain {
    u32 a;
    u32 b;
};

struct Poly {
    virtual void f0();
    virtual Plain* get();
};

struct Holder {
    u8 pad[0x30];
    Poly* m_second;
    Poly* m_first;
};

extern "C" {
void fn_27_3A600(Holder* self, u32 unused, u32 val, u32 mode) {
    if (mode == 1) {
        Plain* p = self->m_first->get();
        p->a = val;
    } else {
        Plain* p = self->m_second->get();
        p->b = val;
    }
}
}
