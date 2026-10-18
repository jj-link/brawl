#pragma force_active on
typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern "C" Vec3f* fn_117_92AC(Vec3f* out, float x, float y, float z)
{
    out->x = x;
    out->y = y;
    out->z = z;
    return out;
}
