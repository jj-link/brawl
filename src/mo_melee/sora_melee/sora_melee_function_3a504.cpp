#include <types.h>
#pragma force_active on

struct fn27Inner {
    virtual void v0();
    virtual fn27Inner* v1();
    virtual void v2();
    virtual void v3();
    u8 pad[0x3c - 4];
    u32 m_3c;
};

struct fn27Outer {
    u8 pad[0x30];
    fn27Inner* m_30;
};

extern "C" {
bool fn_27_3A504(fn27Outer* self, u32 unused, u32 flag) {
    if (flag == 1) {
        return 1;
    }
    fn27Inner* p = self->m_30->v1();
    return (p->m_3c >> 13) & 1;
}
}
