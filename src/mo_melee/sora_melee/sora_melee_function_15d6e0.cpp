#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

struct Target {
    char pad[0x10];
    float scale;
};

extern "C" void fn_27_15D6E0(Target* t, const Vec2f* v)
{
    t->scale = t->scale * v->y;
}
