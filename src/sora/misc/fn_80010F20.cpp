#include <types.h>
#pragma force_active on

extern "C" void fn_80012504(void* a, void* b);
extern void* lbl_8059FF90;

struct FooObj {
    u8 m_pad[0x1c];
    u8 m_flags;
};

extern "C" {
void fn_80010F20(FooObj* self) {
    if (((u32)(self->m_flags >> 4) & 1u) == 1u) {
        fn_80012504(lbl_8059FF90, self);
        self->m_flags &= ~0x10;
    }
}
}
