#pragma force_active on
extern const float lbl_27_rodata_B70;

typedef struct {
    float x;
    float y;
} Vec2Pair;

extern "C" {
Vec2Pair fn_27_7E398(void)
{
    Vec2Pair v;
    v.x = lbl_27_rodata_B70;
    v.y = lbl_27_rodata_B70;
    return v;
}
}
