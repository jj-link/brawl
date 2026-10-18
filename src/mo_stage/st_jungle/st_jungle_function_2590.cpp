#pragma force_active on
typedef struct {
    float x;
    float y;
    float z;
} Vec3;

extern "C" int fn_51_2590(void *self, Vec3 *out)
{
    Vec3 *src = (Vec3 *)((char *)self + 0x3a0);
    out->x = src->x;
    out->y = src->y;
    out->z = src->z;
    return 1;
}
