#include <types.h>
#pragma force_active on

extern "C" void fn_80133C78(void* p);

struct fn27Target {
    u8 pad0[0x71];
    u8 m_71_b0 : 1;
    u8 m_71_b1 : 1;
    u8 m_71_b2 : 1;
    u8 m_71_b3 : 1;
    u8 m_71_b4 : 1;
    u8 m_71_b5 : 1;
    u8 m_71_b6 : 1;
    u8 m_71_b7 : 1;
};

struct fn27Self {
    u8 pad0[0x4];
    fn27Target* m_target;
    u8 pad1[0x30];
    u8 m_38;
    u8 m_39;
};

extern "C" void fn_27_2EAE8(fn27Self* self) {
    if (self->m_target) {
        self->m_target->m_71_b0 = 0;
        fn_80133C78(self->m_target);
    }
    self->m_38 = 5;
    self->m_39 = 0;
}
