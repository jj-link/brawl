#include <types.h>
#pragma force_active on

struct soaArg;
struct soaBase;

struct soaHolder {
    virtual void vf0();
    virtual soaArg* vf1(u32 z);
};

struct soaUser {
    u8 pad[0x30];
    soaBase* m_base;
    u8 pad2[0x58 - 0x34];
    soaHolder* m_holder;
};

extern "C" void fn_27_41EAC(soaArg* a, soaBase* b, s32 off, u32 addr);

extern "C" void fn_27_43664(soaUser* self, s32 x, u32 y, u32 z) {
    soaArg* a = self->m_holder->vf1(z);
    fn_27_41EAC(a, self->m_base, x, y);
}
