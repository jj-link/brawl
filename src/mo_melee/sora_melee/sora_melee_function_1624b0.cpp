#pragma force_active on
struct Vec2f {
    float x, y;
};

struct Vec3f {
    float x, y, z;
};

extern "C" {
extern const float lbl_27_rodata_1FC0;

void fn_27_89D08(int, void*, int, Vec2f*, Vec3f*);

void fn_27_1624B0(void*, void*, Vec2f* speed, void* accesser) {
    Vec3f zero = {
        lbl_27_rodata_1FC0,
        lbl_27_rodata_1FC0,
        lbl_27_rodata_1FC0
    };
    fn_27_89D08(0, accesser, 2, speed, &zero);
}
}
