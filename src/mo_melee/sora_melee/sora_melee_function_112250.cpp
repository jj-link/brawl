#include <types.h>
#pragma force_active on

struct FTBaseClass {
    unsigned char _0[0x4b8];
    s32 m_4b8;
};

extern "C" void fn_27_112250(FTBaseClass*& self, s32 value) {
    self->m_4b8 = value;
}
