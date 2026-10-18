#include <types.h>
#pragma force_active on

struct FnEF144Obj {
    u8 pad[4];
    s32 m_4;
    s16 m_8;
    s16 m_a;
};

extern "C" void fn_27_EF144(FnEF144Obj* p) {
    p->m_4 = -1;
    p->m_8 = 0;
    p->m_a = -1;
}
