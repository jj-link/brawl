#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void f0();
    virtual Inner* f1();
    u8 pad[0x3c - 4];
    u32 m_flags;
};

struct Outer {
    u8 pad[0x30];
    Inner* unk30;
};

extern "C" {
u32 fn_27_3A4BC(Outer* self, void* p2, u32 p3) {
    if (p3 == 1)
        return 1;
    Inner* r = self->unk30->f1();
    return (r->m_flags >> 14) & 1;
}
}
