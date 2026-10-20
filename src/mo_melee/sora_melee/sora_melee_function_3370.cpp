#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct S {
    Vec3f src;
    float pad0xC;
    Vec3f dst;
};

extern "C" void fn_27_3370(S* s)
{
    s->dst.x = s->src.x;
    s->dst.y = s->src.y;
    s->dst.z = s->src.z;
}
