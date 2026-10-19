#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

struct Obj {
    char pad[0x18];
    Vec2 v;
};

extern "C" void fn_27_15CF5C(Obj* self, float s)
{
    Vec2 tmp = self->v;
    tmp.x *= s;
    self->v = tmp;
}
