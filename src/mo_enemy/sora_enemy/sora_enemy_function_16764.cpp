#pragma force_active on
extern "C" {
struct Vec2f { float x; float y; };
Vec2f fn_41_108CC(const Vec2f*, float);
float fn_41_108AC(Vec2f*, Vec2f*);
}
extern float lbl_41_rodata_C68;
inline Vec2f calculate(Vec2f* arg0, Vec2f* arg1)
{
    Vec2f d;
    Vec2f t = fn_41_108CC(arg0, lbl_41_rodata_C68);
    float s = fn_41_108AC(arg0, arg1);
    Vec2f u = fn_41_108CC(&t, s);
    d.x = arg1->x - u.x;
    d.y = arg1->y - u.y;
    return d;
}
extern "C" void fn_41_16764(Vec2f* arg0, Vec2f* arg1, Vec2f* arg2)
{
    Vec2f e = calculate(arg0, arg1);
    arg2->x = e.x;
    arg2->y = e.y;
}