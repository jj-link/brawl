#include <types.h>
#pragma force_active on

extern "C" void fn_10_1D4A8(void* self);
extern "C" void fn_10_1CF64(void* self, u32 arg);

struct SelChar {
    u32 m_data[0x164 / 4];
    s32 m_164[4];
};

extern "C" void fn_10_1D45C(void* self) {
    SelChar* c = (SelChar*)self;
    c->m_164[0] = -1;
    c->m_164[1] = -1;
    c->m_164[2] = -1;
    c->m_164[3] = -1;
    fn_10_1D4A8(self);
    fn_10_1CF64(self, c->m_data[0x44 / 4]);
}
