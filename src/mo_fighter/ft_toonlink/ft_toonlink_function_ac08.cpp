#pragma force_active on

struct Vec3f {
    float x, y, z;
};

extern "C" Vec3f* fn_121_AC08(Vec3f* dst, float x, float y, float z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
    return dst;
}
