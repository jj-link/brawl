#include <types.h>
#pragma force_active on

struct FnObj {
    u32 m_0;
    u32 m_4;
    u32 m_8;
    u32 m_c;
};

void fn_803D66FC(struct FnObj *self, s32 arg1) {
    if (self->m_c == 1 || arg1 == 0) {
        self->m_8 = self->m_0;
        return;
    }
    self->m_8 = arg1;
}
