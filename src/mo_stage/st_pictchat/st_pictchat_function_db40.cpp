#pragma force_active on
typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern "C" void fn_73_DB40(char *self, Vec3 *out)
{
    Vec3 *src = *(Vec3 **)(self + 0x1ac);
    out->x = src->x;
    out->y = src->y;
    out->z = src->z;
}
