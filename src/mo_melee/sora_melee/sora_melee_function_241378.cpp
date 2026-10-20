#include <types.h>
#pragma force_active on

extern "C" void fn_8010F884(void* p);
extern void* lbl_805A0350;

struct FooObj {
    u8 m_pad[0x64];
    u8 m_flags;
};

extern "C" {
void fn_27_241378(FooObj* self) {
    void* p = lbl_805A0350;
    if (p != 0 && ((u32)(self->m_flags >> 6) & 1u) == 1u) {
        fn_8010F884(p);
        self->m_flags &= ~0x40;
    }
}
}
