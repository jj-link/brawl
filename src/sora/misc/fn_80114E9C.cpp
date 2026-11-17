#pragma force_active on
#include <gr/collision/gr_collision.h>
struct Ctx { grCollisionLine* line; int unk4; grCollision* coll; };
struct Words { int x, y; };
inline Vec2f normal(const Vec2f& b, const Vec2f& a) { return Vec2f(-a.m_y, b.m_x); }
extern "C" Vec2f fn_80114E9C(Ctx p) {
    clSegment2D seg;
    p.coll->getSegment(&seg, p.line);
    Vec2f tb;
    Vec2f ta;
    Vec2f b2;
    Vec2f a2;
    ta.m_x = seg.m_p1Pos.m_x - seg.m_p0Pos.m_x;
    ta.m_y = seg.m_p1Pos.m_y - seg.m_p0Pos.m_y;
    tb.m_x = seg.m_p1Pos.m_x - seg.m_p0Pos.m_x;
    tb.m_y = seg.m_p1Pos.m_y - seg.m_p0Pos.m_y;
    *(Words*)&b2 = *(Words*)&tb;
    *(Words*)&a2 = *(Words*)&ta;
    return normal(b2, a2);
}
