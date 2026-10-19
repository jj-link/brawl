#pragma force_active on
typedef struct Vec3
{
    float x;
    float y;
    float z;
} Vec3;

extern "C" void fn_90_12BC(Vec3 *dst, const Vec3 *src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
