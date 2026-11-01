#pragma force_active on
extern const float lbl_27_rodata_BB0;

struct Vec2 {
    float x;
    float y;
};

struct Obj {
    int pad[2];
    Vec2 v;
};

extern "C" void fn_27_8A3E0(Obj* obj, const Vec2* in)
{
    Vec2 tmp;
    Vec2 f;
    Vec2 c;
    Vec2 a;

    tmp.x = in->x;
    tmp.y = in->y;

    float d = tmp.x * obj->v.x + tmp.y * obj->v.y;

    a.x = tmp.x * lbl_27_rodata_BB0;
    a.y = tmp.y * lbl_27_rodata_BB0;
    Vec2 b = a;

    c.x = b.x * d;
    c.y = b.y * d;
    Vec2 e = c;

    f.x = obj->v.x - e.x;
    f.y = obj->v.y - e.y;
    Vec2 g = f;

    obj->v = g;
}
