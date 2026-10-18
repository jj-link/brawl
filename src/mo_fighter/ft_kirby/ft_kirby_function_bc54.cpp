#pragma force_active on
struct Vec3f {
    float x, y, z;
};

extern "C" Vec3f* fn_96_BC54(Vec3f* v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}
