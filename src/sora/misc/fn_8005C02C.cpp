#include <types.h>
#pragma force_active on

struct Foo {
    u8 pad[0x18];
    u16 m_val;
};

struct Bar {
    u8 pad[0x18];
    Foo* m_foo;
};

extern "C" u16 fn_8005C02C(Bar* p) {
    if (p->m_foo == nullptr) {
        return 0;
    }
    return p->m_foo->m_val;
}
