#pragma force_active on
struct Vec2f { float x; float y; };
struct Vec3f { float x; float y; float z; };

extern "C" extern const float lbl_27_rodata_1FC0;
extern "C" void fn_27_89D08(int, void*, int, Vec2f*, Vec3f*);

extern "C" void fn_27_1645AC(int, int, const float* value, void* accesser) {
    float x = *value;
    Vec2f v2;
    v2.x = x;
    Vec3f v3 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    v2.y = lbl_27_rodata_1FC0;
    fn_27_89D08(3, accesser, 0x10, &v2, &v3);
}
