#pragma force_active on
typedef struct Vec3
{
    float x;
    float y;
    float z;
} Vec3;

extern "C" void fn_54_29B4(char *self, Vec3 *out)
{
    if (out == 0) {
        return;
    }
    unsigned char idx = *(unsigned char *)(self + 0x7ec);
    Vec3 *v = (Vec3 *)(self + idx * 12 + 0x7b0);
    out->x = v->x;
    out->y = v->y;
    out->z = v->z;
}
