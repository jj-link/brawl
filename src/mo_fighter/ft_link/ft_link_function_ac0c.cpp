#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
Vec3f* fn_93_AC0C(Vec3f* v, float x, float y, float z);
}

Vec3f* fn_93_AC0C(Vec3f* v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}
