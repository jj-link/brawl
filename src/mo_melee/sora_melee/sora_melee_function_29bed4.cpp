#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(u32 p);
};

struct Mid {
    u8 pad[0x64];
    Inner* m_64;
};

struct Outer {
    u8 pad[0xD8];
    Mid* m_D8;
};

struct Arg {
    u8 pad[0x60];
    Outer* m_60;
};

extern "C" {
void fn_27_29BED4(void* unused, Arg* a) {
    a->m_60->m_D8->m_64->v4(0x10000000);
}
}
