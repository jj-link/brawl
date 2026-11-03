#include <types.h>
#pragma force_active on

extern "C" s32 fn_8004465C(void* p);

struct Obj {
    u8 pad0[0x42];
    u8 m_idx;
    u8 pad1[0xC8 - 0x43];
    u8 m_sub[4];
    u32 m_bits[9];
    s16* m_ptrs[256];
};

extern "C" void fn_80112C98(Obj* self, s16* out) {
    u16 idx = self->m_idx;
    u32 bit = 1 << (idx & 31);
    if (!(self->m_bits[idx >> 5] & bit)) {
        self->m_bits[(u8)idx >> 5] |= bit;
        self->m_idx++;
    } else {
        idx = (u16)fn_8004465C(self->m_sub);
        self->m_bits[idx >> 5] |= 1 << (idx & 31);
        self->m_idx = idx + 1;
    }
    *out = (u8)idx;
    self->m_ptrs[idx] = out;
}
