#pragma force_active on
#pragma scheduling off

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

extern "C" {
extern const float lbl_27_rodata_76AC;

Vec3* fn_27_331BEC(Vec3*, float, float, float);
void fn_27_89D08(int, void*, int, Vec2*, Vec3*);

void fn_27_332660(void*, void*, const float* speed, void* accesser) {
    Vec3 rotation;
    Vec2 velocity;

    velocity.x = *speed;
    velocity.y = lbl_27_rodata_76AC;

    fn_27_89D08(2, accesser, 0, &velocity,
        fn_27_331BEC(&rotation, lbl_27_rodata_76AC,
                    lbl_27_rodata_76AC, lbl_27_rodata_76AC));
}
}
