#pragma force_active on
extern "C" const float lbl_126_rodata_8;

struct Vec3fLike {
    float x;
    float y;
    float z;
};

extern "C" void fn_126_88EC(Vec3fLike* object) {
    object->x = lbl_126_rodata_8;
    object->y = lbl_126_rodata_8;
    object->z = lbl_126_rodata_8;
}
