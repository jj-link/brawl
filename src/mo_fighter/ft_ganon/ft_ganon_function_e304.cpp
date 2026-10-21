#pragma force_active on
#pragma scheduling off
#pragma optimize_for_size on

struct Vec2 {
    float x, y;
};

union Copy2 {
    Vec2 value;
    unsigned int words[2];
};

struct Vec3 {
    float x, y, z;
};

extern "C" {
extern const float lbl_109_rodata_28;

Vec3* fn_109_8B54(Vec3*, float, float, float);
void fn_27_89D08(int, void*, int, Vec2*, Vec3*);

void fn_109_E304(void*, void*, const Vec2* source, void* accesser) {
    Copy2 first;
    Vec2 zero;
    Vec2 second;
    Vec3 rotation;
    Vec3 rotation2;

    zero.x = lbl_109_rodata_28;
    zero.y = lbl_109_rodata_28;
    fn_27_89D08(0, accesser, 4, &zero,
        fn_109_8B54(&rotation, lbl_109_rodata_28,
                    lbl_109_rodata_28, lbl_109_rodata_28));

    first = *(const Copy2*)source;
    second.x = first.value.x;
    second.y = lbl_109_rodata_28;
    fn_27_89D08(2, accesser, 0, &second,
        fn_109_8B54(&rotation2, lbl_109_rodata_28,
                    lbl_109_rodata_28, lbl_109_rodata_28));
}
}
