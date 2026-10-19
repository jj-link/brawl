#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void fn_48_10E0(char *self, Vec3 *out)
{
    if (out != 0) {
        Vec3 *v = (Vec3 *)(self + 0x2b8);
        out->x = v->x;
        out->y = v->y;
        out->z = v->z;
    }
}
