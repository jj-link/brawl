#pragma force_active on
extern "C" const float lbl_102_rodata_8;

struct Vec3fTriple {
    float x;
    float y;
    float z;
};

extern "C" void fn_102_B0E8(Vec3fTriple* object) {
    object->x = lbl_102_rodata_8;
    object->y = lbl_102_rodata_8;
    object->z = lbl_102_rodata_8;
}
