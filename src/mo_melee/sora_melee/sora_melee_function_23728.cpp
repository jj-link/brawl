#pragma force_active on
struct Vec3
{
    float x;
    float y;
    float z;
};

struct Obj
{
    unsigned char pad[0x6C];
    Vec3 v;
};

extern "C" void fn_27_23728(Obj* self, const Vec3* src)
{
    self->v = *src;
}
