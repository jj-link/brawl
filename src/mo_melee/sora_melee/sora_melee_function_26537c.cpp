#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_263A30(void* p);

struct FnDummy27 {
    char pad[0x14c];
    void* m_ptr;
};

void fn_27_26537C(FnDummy27* self) {
    if (self->m_ptr) {
        fn_27_263A30(self->m_ptr);
    }
}
}
