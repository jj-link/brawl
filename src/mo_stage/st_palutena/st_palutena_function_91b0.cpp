#pragma force_active on
typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern "C" void fn_67_91B0(char *obj, Vec3 *out)
{
    if (out == 0) {
        return;
    }
    out->x = *(float *)(obj + 0x1e8);
    out->y = *(float *)(obj + 0x1ec);
    out->z = *(float *)(obj + 0x1f0);
}
