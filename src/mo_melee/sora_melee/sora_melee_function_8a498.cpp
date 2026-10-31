#pragma force_active on

typedef struct {
    float x;
    float y;
} Vec2;

typedef struct {
    char pad[0x10];
    Vec2 v;
} Obj;

extern const float lbl_27_rodata_BB0;

extern "C" void fn_27_8A498(Obj* obj, const Vec2* v)
{
    Vec2 tmp;
    Vec2 f;
    Vec2 c;
    Vec2 a;

    tmp.x = v->x;
    tmp.y = v->y;

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
