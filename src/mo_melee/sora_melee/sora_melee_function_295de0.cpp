#include <types.h>
#pragma force_active on

struct Foo {
    u32 m_0;
    u32 m_4;
    u32 m_8;
};

extern "C" u32 fn_27_295DE0(Foo* self) {
    return (self->m_8 >> 19) & 1;
}
