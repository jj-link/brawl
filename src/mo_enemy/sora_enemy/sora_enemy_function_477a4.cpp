#pragma force_active on
union Vec3 {
    struct { float x, y, z; };
    unsigned int words[3];
};

extern "C" const float lbl_41_rodata_1024;

extern "C" void fn_41_477A4(Vec3* dst, const Vec3* src) {
    *dst = *src;
    dst->x *= lbl_41_rodata_1024;
    dst->y *= lbl_41_rodata_1024;
    dst->z *= lbl_41_rodata_1024;
}
