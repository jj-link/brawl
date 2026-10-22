#include <types.h>
#pragma force_active on

extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80461AF8[];

struct fn80155E84Obj {
    u8 pad[0x388];
    u8 m_388;
    u8 pad2[0x398 - 0x389];
    u8 m_398;
};

extern "C" void fn_80155E84(fn80155E84Obj* self, s32 arg1, s32 arg2) {
    netReport__FPCce(lbl_80461AF8);
    if (arg2 == 6) {
        self->m_398 = 1;
    } else if (arg2 == 7) {
        self->m_398 = 1;
    }
    if (arg1 != 0) {
        self->m_388 = 1;
    }
}
