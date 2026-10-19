#pragma force_active on
struct Vec2Pair {
    float x;
    float y;
};

extern const float lbl_41_rodata_18;

extern "C" {
Vec2Pair fn_41_C4CC() {
    Vec2Pair v;
    v.x = lbl_41_rodata_18;
    v.y = lbl_41_rodata_18;
    return v;
}
}
