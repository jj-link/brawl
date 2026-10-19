#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

struct Vec3f {
    float x;
    float y;
    float z;
};

class soModuleAccesser;

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);

void fn_27_1629C4(int, int, Vec2f* vec, soModuleAccesser* accesser) {
    Vec3f zero;
    zero.x = lbl_27_rodata_1FC0;
    zero.y = lbl_27_rodata_1FC0;
    zero.z = lbl_27_rodata_1FC0;
    fn_27_89D08(0, accesser, 9, vec, &zero);
}
}
