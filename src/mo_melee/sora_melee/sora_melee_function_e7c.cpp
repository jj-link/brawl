#pragma force_active on
struct Vec3 {
    float x, y, z;
};

extern "C" void fn_27_E7C(Vec3* destination, const Vec3* source)
{
    *destination = *source;
}
