#pragma force_active on
class soModuleAccesser;

struct Vec2f {
    float x;
    float y;
};

struct Vec3f {
    float x;
    float y;
    float z;
};

extern const float lbl_27_rodata_1FC0;

extern "C" void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);

extern "C" void fn_27_162BE4(int, int, Vec2f* vec, soModuleAccesser* accesser) {
    float f = lbl_27_rodata_1FC0;
    Vec3f zero = { f, f, f };
    fn_27_89D08(3, accesser, 0x14, vec, &zero);
}
