#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

struct Target {
    char pad[8];
    float x;
    float y;
};

extern "C" void fn_27_8A378(Target* self, const Vec2* scale) {
    Vec2 s;
    s.x = scale->x;
    s.y = scale->y;
    self->x = self->x * s.x;
    self->y = self->y * s.y;
}
