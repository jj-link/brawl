#include <types.h>
#pragma force_active on

extern "C" {
void fn_80204A40(void* arg);

struct Foo {
    void* m_vtable;
    void* m_ptr;
};

void fn_801BBC08(Foo* self) {
    if (self->m_ptr)
        fn_80204A40(self->m_ptr);
}
}
