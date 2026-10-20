#pragma force_active on
struct Vec3Store {
    char pad[0x14];
    float x;
    float y;
    float z;
};

extern "C" void fn_27_C3170(Vec3Store *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}
