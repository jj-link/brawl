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

extern "C" const float lbl_27_rodata_1FC0;
extern "C" void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);

extern "C" void fn_27_1623D8(int, int, Vec2f* motion, soModuleAccesser* accesser) {
    float v = lbl_27_rodata_1FC0;
    Vec3f zero = {v, v, v};
    fn_27_89D08(3, accesser, 9, motion, &zero);
}
