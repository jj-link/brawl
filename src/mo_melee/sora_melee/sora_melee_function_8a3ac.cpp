#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

struct Obj {
    char pad[0x10];
    Vec2 scale;
};

extern "C" {
void fn_27_8A3AC(Obj* self, const Vec2* v) {
    Vec2 tmp;
    tmp.x = v->x;
    tmp.y = v->y;
    self->scale.x *= tmp.x;
    self->scale.y *= tmp.y;
}
}
