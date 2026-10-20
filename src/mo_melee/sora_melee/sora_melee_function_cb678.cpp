#include <types.h>
#pragma force_active on

struct Foo {
    u32 m_0;
    u32 m_4;
    unsigned : 21;
    unsigned m_9 : 1;
    unsigned : 10;
};

extern "C" s32 fn_27_CB678(Foo* self) {
    return self->m_9;
}
