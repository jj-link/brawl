#pragma force_active on
struct Vec2 {
    float x, y;
};

struct Object {
    float pad[2];
    Vec2 value;
};

extern "C" void fn_27_8A578(Object* dst, int unused, const Vec2* src)
{
    dst->value = *src;
}
