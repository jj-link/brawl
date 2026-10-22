#include <types.h>
#pragma force_active on

struct Fn80189A34Obj {
    u8 pad[0x38];
    u32 m_38;
    struct {
        u32 a : 8;
        u32 b : 4;
        u32 c : 20;
    } m_3C;
    u8* m_40;
};

extern "C" void fn_80189A34(Fn80189A34Obj* self, u32 n) {
    u32 r0;
    u32 r9;
    u32 r11;
    u32 i;
    u8* p;
    u8* base;

    if (n == 0) {
        return;
    }
    r0 = self->m_38;
    r9 = *(u32*)&self->m_3C;
    r11 = (r9 >> 20) & 0xF;
    base = self->m_40 + ((r0 >> 24) & 0xF) * 0x14;
    p = base + (r0 >> 28) * 0x1C + ((r9 >> 18) & 0x3C);
    for (i = r11; i < n; i++) {
        if (p != 0) {
            p[3] = 0;
            p[0] = 1;
            p[1] = 4;
            p[2] = 0x3C;
        }
        p += 4;
    }
    self->m_3C.b = n;
}
