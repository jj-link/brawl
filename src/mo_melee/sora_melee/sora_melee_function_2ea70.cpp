#include <types.h>
#pragma force_active on

extern "C" void fn_80133C1C(void* p);
extern "C" void* fn_27_2EBBC(void* a, void* b);

struct SoSub {
    u8 pad0[0x10];
    void* m_arg10;
    u8 pad1[0x73 - 0x14];
    u8 m_flags73;
};

struct SoObj {
    u8 pad0[4];
    SoSub* m_sub;
};

extern "C" void fn_27_2EA70(SoObj* self, void* a, void* b) {
    if (self->m_sub != 0) {
        fn_80133C1C(self->m_sub);
        self->m_sub->m_arg10 = a;
        self->m_sub->m_flags73 &= ~0x10;
    }
    fn_27_2EBBC(self, b);
}
