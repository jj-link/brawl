#include <types.h>
#pragma force_active on

struct Xyz {
    u16* m_ptr;
    s8* m_table;
};

extern "C" s32 fn_801B6A10(Xyz* self, u32 idx, s32 val) {
    u16* p = self->m_ptr;
    s32 ok = 0;
    if (p != NULL && self->m_table != NULL) {
        ok = 1;
    }
    if (ok && idx < 8) {
        if (val < 0) {
            self->m_table[idx] = -1;
            return 1;
        }
        if (val < *p) {
            self->m_table[idx] = (s8)val;
            return 1;
        }
    }
    return 0;
}
