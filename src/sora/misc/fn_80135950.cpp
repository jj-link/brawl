#include <types.h>
#include <mt/mt_vector.h>

#pragma force_active on

extern const f32 lbl_805A2A40;

struct Self {
    u8 pad0[8];
    u32 flags;
    u8 pad1[0x3C - 0x0C];
    Vec2f a;
    Vec2f b;
    Vec2f c;
    u8 pad2[4];
    s32 mode;
};

extern "C" void fn_80135950(const Self* self, Vec2f* base, f32* out) {
    Vec2f a, b, c;
    __memcpy(&a, &self->a, sizeof(Vec2f));
    s32 flags = self->flags;
    __memcpy(&b, &self->b, sizeof(Vec2f));
    __memcpy(&c, &self->c, sizeof(Vec2f));

    if (((s32)((flags << 0x18) | ((flags >> 8) & 0x800000)) >> 0x18) == 0) {
        a.m_x = -a.m_x;
        b.m_x = -b.m_x;
    } else {
        c.m_x = -c.m_x;
    }

    Vec2f p;
    __memcpy(&p, &(*base + a), sizeof(Vec2f));

    Vec2f q1, q0;
    switch (self->mode) {
    case 0:
    default:
        q1 = p;
        q0 = p + b;
        break;
    case 1:
        q1 = p + c;
        q0 = p;
        break;
    case 2:
        f32 m = b.m_y > c.m_y ? b.m_y : c.m_y;
        q1 = p + Vec2f(b.m_x, m);
        q0 = p + Vec2f(c.m_x, lbl_805A2A40);
        break;
    }

    register f32 f0, f1, f2, f3, f4, f5, f6, f7;
    f6 = q0.m_x;
    f7 = q1.m_x;
    f3 = q0.m_y;
    f4 = q1.m_y;
    asm { ps_sub f5, f7, f6 }
    asm { ps_sub f1, f7, f6 }
    asm { ps_sub f2, f4, f3 }
    asm { ps_sub f0, f4, f3 }
    asm { ps_sel f5, f5, f6, f7 }
    asm { ps_sel f2, f2, f3, f4 }
    asm { ps_sel f1, f1, f7, f6 }
    asm { ps_sel f0, f0, f4, f3 }
    out[0] = f5;
    out[1] = f2;
    out[2] = f1;
    out[3] = f0;
}
