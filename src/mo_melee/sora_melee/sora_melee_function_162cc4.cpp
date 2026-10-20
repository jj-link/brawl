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

extern "C" void fn_27_162CC4(int, int, int, soModuleAccesser* accesser) {
    float v = lbl_27_rodata_1FC0;
    Vec3f motion = {v, v, v};
    Vec2f gravity = {v, v};
    fn_27_89D08(2, accesser, 7, &gravity, &motion);
}
