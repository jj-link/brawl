#include <types.h>
#pragma force_active on

extern "C" {

struct Foo {
    u32 m_0;
    u32 m_4;
    unsigned : 9;
    unsigned m_field : 1;
};

u32 fn_27_C9FB0(const struct Foo* self) {
    return self->m_field;
}

}
