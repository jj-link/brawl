#pragma force_active on

struct Vec2f {
    float x;
    float y;
};

struct Holder {
    char pad[0x8c];
    Vec2f v;
};

extern "C" void fn_801376A0(Holder *dst, const Vec2f *src)
{
    dst->v = src[0];
}
