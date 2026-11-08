#include <types.h>
#pragma force_active on
struct Obj {
    u8 pad0[0xDC];
    u32* m_dc;
    u32 pad1;
    s32 m_e4;
    u32 m_e8;
};
static inline u32* find(u32* f, u32* l, const u32& v) {
    while (f != l && *f != v) f++;
    return f;
}
extern "C" u32 fn_801B34EC(Obj* self, u32 value) {
    self->m_e8 = value;
    if (value != 0) {
        u32* p = self->m_dc;
        u32* end = p + self->m_e4;
        if (find(p, end, self->m_e8) == end) self->m_e8 = 0;
    }
    return self->m_e8 != 0;
}
