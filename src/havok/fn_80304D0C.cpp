#pragma force_active on
struct Vec4
{
    float x;
    float y;
    float z;
    float w;
};

extern "C" void fn_80304D0C(Vec4 *out, const Vec4 *a, const Vec4 *b)
{
    out->x = a->x * b->x;
    out->y = a->y * b->y;
    out->z = a->z * b->z;
    out->w = a->w * b->w;
}
