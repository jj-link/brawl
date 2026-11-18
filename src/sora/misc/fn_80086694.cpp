#include <mt/mt_vector.h>
#pragma force_active on
struct RectF { float l, t, r, b; };
struct RectI { int l, t, r, b; };
struct Buf { RectF rect; char pad[10]; short flag; };
struct Outer { char pad[16]; Buf* buf; };
extern "C" void fn_8011728C(Buf*, int, int);

static inline void makeRect(RectF& r, const Vec2f& a, const Vec2f& b) {
    register float t0, t2, t1, t3, ax, bx, by, ay;
    bx = b.m_x;
    ax = a.m_x;
    by = b.m_y;
    ay = a.m_y;
    asm { ps_sub t0, bx, ax }
    asm { ps_sub t1, bx, ax }
    asm { ps_sub t2, by, ay }
    asm { ps_sel t0, t0, ax, bx }
    asm { ps_sub t3, by, ay }
    asm { ps_sel t2, t2, ay, by }
    asm { ps_sel t1, t1, bx, ax }
    asm { ps_sel t3, t3, by, ay }
    r.l = t0;
    r.t = t2;
    r.r = t1;
    r.b = t3;
}

extern "C" void fn_80086694(Outer* self, const Vec2f* pos, const float* radius) {
    self->buf->flag = 0;
    Vec2f b(pos->m_x + *radius, pos->m_y - *radius);
    Vec2f a(pos->m_x - *radius, pos->m_y + *radius);
    RectF r;
    makeRect(r, a, b);
    *(RectI*)&self->buf->rect = *(RectI*)&r;
    fn_8011728C(self->buf, 0, 0);
}