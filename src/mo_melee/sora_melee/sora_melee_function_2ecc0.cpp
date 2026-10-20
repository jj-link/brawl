#include <types.h>
#pragma force_active on

extern "C" void fn_80133E14(void* p);

struct fn27Obj {
    u8 pad0[4];
    void* m_ptr4;
    u8 pad1[0x36 - 8];
    s16 m_16;
    u32 m_38;
};

extern "C" void fn_27_2ECC0(fn27Obj* self) {
    if (self->m_ptr4 != 0) {
        fn_80133E14(self->m_ptr4);
    }
    self->m_16 = 0;
    self->m_38 &= ~0x8;
}
