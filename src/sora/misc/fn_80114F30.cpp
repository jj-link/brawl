#include <gr/collision/gr_collision.h>
#pragma force_active on
struct Words { int x, y; };
struct Context { grCollisionLine* line; int unused; grCollision* collision; };
extern "C" bool fn_80114F30(Context ctx, Vec2f* point) {
    clSegment2D seg;
    ctx.collision->getSegment(&seg, ctx.line);
    Vec2f a, b, at, bt;
    at.m_x = seg.m_p0Pos.m_x - point->m_x;
    at.m_y = seg.m_p0Pos.m_y - point->m_y;
    bt.m_x = seg.m_p1Pos.m_x - point->m_x;
    bt.m_y = seg.m_p1Pos.m_y - point->m_y;
    *(Words*)&a = *(Words*)&at;
    *(Words*)&b = *(Words*)&bt;
    return !(a.lengthSq() > b.lengthSq());
}