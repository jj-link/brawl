#pragma force_active on
struct Vec3f {
    float x, y, z;
};

extern const float lbl_27_rodata_33D8;
extern const float lbl_27_rodata_33F8;

extern "C" void getLucarioFinalTechniquePosition__5StageFP5Vec3f(void*, Vec3f* position) {
    position->x = lbl_27_rodata_33D8;
    position->y = lbl_27_rodata_33F8;
    position->z = lbl_27_rodata_33D8;
}
