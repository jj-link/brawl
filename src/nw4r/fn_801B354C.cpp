#include <types.h>
#pragma force_active on
struct Obj {
    u8 pad0[0xDC];
    u32* m_dc;
    u32 pad1;
    s32 m_e4;
    u32 m_e8;
    s32 count() const { return m_e4; }
};

static inline u32* find(u32* f, u32* l, const u32& v) {
    while (f != l && *f != v) f++;
    return f;
}

extern "C" u32 fn_801B354C(Obj* self, s32 idx) {
    if (idx >= 0 && idx < self->count()) {
        u32* p = self->m_dc;
        self->m_e8 = p[idx];
        if (self->m_e8 != 0) {
            u32* end = p + self->m_e4;
            if (find(p, end, self->m_e8) == end) self->m_e8 = 0;
        }
        return self->m_e8 != 0;
    }
    return 0;
}
