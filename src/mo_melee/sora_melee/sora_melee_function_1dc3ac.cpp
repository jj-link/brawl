#pragma force_active on
extern const float lbl_27_rodata_27E0;
extern const float lbl_27_rodata_27E4;
struct Vec2 { float x, y; };
struct Obj { int pad[2]; float value; };
extern "C" void fn_27_1DC3AC(Obj* out, const Vec2* v) {
    Vec2 r;
    Vec2 dir;
    Vec2 g;
    Vec2 e;
    Vec2 a;
    r.y = out->value;
    r.x = lbl_27_rodata_27E0;
    dir.x = v->x;
    dir.y = v->y;
    float d = dir.x * r.x + dir.y * r.y;
    a.x = dir.x * lbl_27_rodata_27E4;
    a.y = dir.y * lbl_27_rodata_27E4;
    Vec2 b = a;
    e.x = b.x * d;
    e.y = b.y * d;
    Vec2 f = e;
    g.x = r.x - f.x;
    g.y = r.y - f.y;
    Vec2 h = g;
    r.x = h.x;
    r.y = h.y;
    out->value = r.y;
}
