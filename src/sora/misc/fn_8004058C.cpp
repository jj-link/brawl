#pragma force_active on
struct Vec2 { float x, y; };
struct Rect { Vec2 p; Vec2 s; };
inline void convert(const Rect* a, Rect* b, float x, float y)
{
    Vec2 t = {x + a->s.x, y + a->s.y};
    b->p.x = x;
    Vec2 u = t;
    b->p.y = y;
    b->s.x = u.x;
    b->s.y = u.y;
}
extern "C" void fn_8004058C(const Rect* a, Rect* b)
{
    float y;
    float x;
    x = a->p.x;
    y = a->p.y;
    convert(a, b, x, y);
}