#pragma force_active on
extern const float lbl_805A13A4;
struct Vec2f {
    float x, y;
    Vec2f() {}
    Vec2f(float a, float b) : x(a), y(b) {}
};
struct Obj {
    char pad0[0x1C];
    unsigned char flags;
    char pad1[0x48 - 0x1D];
    Vec2f p[4];
};
extern "C" void fn_8001133C(Obj* obj, const Vec2f* a, const Vec2f* b) {
    float lx, ly, ux, uy;
    float half = lbl_805A13A4;
    ly = a->y - half * b->y;
    lx = a->x - half * b->x;
    ux = a->x + half * b->x;
    uy = a->y + half * b->y;
    obj->flags |= 0x20;
    obj->p[0] = Vec2f(lx, ly);
    obj->p[1] = Vec2f(ux, ly);
    obj->p[2] = Vec2f(ux, uy);
    obj->p[3] = Vec2f(lx, uy);
}
