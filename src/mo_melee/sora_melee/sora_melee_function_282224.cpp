#include <types.h>
#pragma force_active on

struct FnObj27 {
    u32 m_pad0;
    s16 m_id;
    s16 m_pad6;
    s32 m_count;
};

extern "C" void fn_27_282224(FnObj27 *p, s32 id) {
    if (p->m_id == id) {
        return;
    }
    p->m_id = id;
    if (id <= -1) {
        return;
    }
    p->m_count = 0;
}
