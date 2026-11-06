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
extern const float lbl_27_rodata_76AC;

float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
Vec3* fn_27_331BEC(Vec3*, float, float, float);
void fn_27_89D08(int, void*, int, Vec2*, Vec3*);

void fn_27_331ED0(void*, void*, void*, void* a) {
    float x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        a, 0xfa8, 0);
    Vec2 first;
    first.x = lbl_27_rodata_76AC;
    first.y = x;
    Vec3 rotation;
    fn_27_89D08(
        1, a, 0, &first,
        fn_27_331BEC(&rotation, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));

    Vec2 second;
    second.x = lbl_27_rodata_76AC;
    second.y = lbl_27_rodata_76AC;
    Vec3 rotation2;
    fn_27_89D08(
        0, a, 6, &second,
        fn_27_331BEC(&rotation2, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));
}
}