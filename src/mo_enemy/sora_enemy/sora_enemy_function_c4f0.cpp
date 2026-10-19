#pragma force_active on
extern "C" {
struct Vec2Pair {
    float x;
    float y;
};

extern const float lbl_41_rodata_18;

Vec2Pair fn_41_C4F0() {
    Vec2Pair v;
    v.x = lbl_41_rodata_18;
    v.y = lbl_41_rodata_18;
    return v;
}
}
