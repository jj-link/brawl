#pragma force_active on
struct soModuleAccesser;
struct Vec2f { float x, y; };
struct Vec3f { float x, y, z; };

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

extern "C" void fn_27_1646FC(int, int, const float* value, soModuleAccesser* accesser) {
    Vec2f v2;
    v2.y = value[1];
    Vec3f v3 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    v2.x = lbl_27_rodata_1FC0;
    fn_27_89D08(1, accesser, 4, &v2, &v3);
}
