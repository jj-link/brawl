#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

struct Rect4 {
    Vec2f a, b;
    Rect4(const Vec2f& p, const Vec2f& q) {
        a.m_x = p.m_x; a.m_y = p.m_y; b.m_x = q.m_x; b.m_y = q.m_y;
    }
};
struct Shape { Rect4 box; u32 pad[2]; Rect4 box2; };
struct Self { u32 unk0; Rect4* b4; Shape* s8; float w, h; void* list[16]; u32 count; };
struct Item { u32 pad[11]; Rect4 box; };
extern "C" int fn_80041D64(void*, void*);
extern "C" int fn_27_1ED404(void*, Vec2f*, Vec2f*, int, int, void*);
extern void* g_aiMgr;
extern const float lbl_27_rodata_2B80[];
static inline bool blocked(void* mgr, Vec2f* a, Vec2f* b, int mask, int flag, void* obj) {
    int result = fn_27_1ED404(mgr, a, b, mask, flag, obj);
    return (u32)(-result | result) >> 31;
}

extern "C" int fn_27_1F2FB0(Self* self, Item* item) {
    const float* const k = lbl_27_rodata_2B80;
    if (self->count < 16) {
        Rect4* ib = &item->box;
        Rect4 rectA(Vec2f(self->s8->box.a.m_x - self->w, self->s8->box.a.m_y - self->h), Vec2f(self->s8->box.b.m_x + self->w, self->s8->box.b.m_y + self->h));
        if (fn_80041D64(ib, &rectA)) {
            Rect4 rectB(Vec2f(self->b4->a.m_x - self->w, self->b4->a.m_y - self->h), Vec2f(self->b4->b.m_x + self->w, self->b4->b.m_y + self->h));
            if (fn_80041D64(ib, &rectB)) {
                Vec2f vB, vA;
                vA.m_x = k[33] * (ib->a.m_x + ib->b.m_x);
                if (vA.m_x > k[33] * (self->s8->box2.a.m_x + self->s8->box2.b.m_x)) {
                    vB = self->s8->box2.b;
                    vB.m_x += k[21];
                } else {
                    vB = self->s8->box2.a;
                    vB.m_x -= k[21];
                }
                vB.m_y += k[86];
                if (vB.m_y < ib->a.m_y) vA.m_y = ib->a.m_y;
                else if (vB.m_y > ib->b.m_y) vA.m_y = ib->b.m_y;
                else vA.m_y = vB.m_y;
                if (!blocked(g_aiMgr, &vA, &vB, 0xFF, 0, self->b4) ||
                    (nw4r::math::FAbs(vB.m_x - vA.m_x) < k[33] * self->w &&
                     vB.m_y - vA.m_y < k[77] * self->h &&
                     !blocked(g_aiMgr, &vA, &Vec2f(vB.m_x, vA.m_y), 0xFF, 0, self->b4) &&
                     !blocked(g_aiMgr, &Vec2f(vB.m_x, vA.m_y), &vB, 0xFF, 0, self->b4))) {
                    self->list[self->count] = item;
                    self->count++;
                }
            }
        }
    }
    return 1;
}