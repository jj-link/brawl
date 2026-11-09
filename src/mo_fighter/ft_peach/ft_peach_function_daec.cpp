#pragma scheduling off
#pragma optimize_for_size on
#pragma force_active on

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

extern "C" {
extern const float lbl_103_rodata_14;

float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
Vec3* fn_103_9594(Vec3*, float, float, float);
void fn_27_89D08(int, void*, int, Vec2*, Vec3*);

void fn_103_DAEC(void*, void*, void*, void* accesser) {
    float x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfa8, 0);

    Vec2 first;
    first.x = lbl_103_rodata_14;
    first.y = x;
    Vec3 rotation;
    fn_27_89D08(
        1, accesser, 0, &first,
        fn_103_9594(&rotation, lbl_103_rodata_14,
                    lbl_103_rodata_14, lbl_103_rodata_14));

    Vec2 second;
    second.x = lbl_103_rodata_14;
    second.y = lbl_103_rodata_14;
    Vec3 rotation2;
    fn_27_89D08(
        0, accesser, 6, &second,
        fn_103_9594(&rotation2, lbl_103_rodata_14,
                    lbl_103_rodata_14, lbl_103_rodata_14));
}
}