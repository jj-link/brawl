#pragma force_active on
extern "C" const float lbl_104_rodata_8;

struct Vec3fZero {
    float x;
    float y;
    float z;
};

extern "C" void fn_104_CEA8(Vec3fZero* object) {
    object->x = lbl_104_rodata_8;
    object->y = lbl_104_rodata_8;
    object->z = lbl_104_rodata_8;
}
