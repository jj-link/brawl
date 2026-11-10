#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_line.h>
#include <mt/mt_coll2d.h>
#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on
struct Words { int x, y; };
struct Context { grCollisionLine* line; int unused; grCollision* collision; };
extern "C" Words fn_80114DAC(Context ctx, Vec2f* point) {
    clSegment2D seg;
    ctx.collision->getSegment(&seg, ctx.line);
    Vec2f a, b, at, bt;
    at.m_x = seg.m_p0Pos.m_x - point->m_x;
    at.m_y = seg.m_p0Pos.m_y - point->m_y;
    bt.m_x = seg.m_p1Pos.m_x - point->m_x;
    bt.m_y = seg.m_p1Pos.m_y - point->m_y;
    *(Words*)&a = *(Words*)&at;
    *(Words*)&b = *(Words*)&bt;
    return a.lengthSq() > b.lengthSq() ? *(Words*)&seg.m_p0Pos : *(Words*)&seg.m_p1Pos;
}