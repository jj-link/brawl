#pragma force_active on
extern const float lbl_41_rodata_BE0;

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void fn_41_FCC0(void* self)
{
    unsigned char* p = static_cast<unsigned char*>(self);
    *reinterpret_cast<int*>(p + 0xC8) = 5;
    *reinterpret_cast<int*>(p + 0xCC) = -1;
    *reinterpret_cast<int*>(p + 0xC4) = -1;

    Vec3 value;
    value.x = lbl_41_rodata_BE0;
    value.y = lbl_41_rodata_BE0;
    value.z = lbl_41_rodata_BE0;
    *reinterpret_cast<Vec3*>(p + 0xD0) = value;
}
