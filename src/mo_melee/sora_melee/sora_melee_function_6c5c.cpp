#pragma force_active on
typedef struct {
    float x;
    float y;
} Vec2Pair;

extern const float lbl_27_rodata_7C;

extern "C" Vec2Pair fn_27_6C5C(void)
{
    Vec2Pair v;
    v.x = lbl_27_rodata_7C;
    v.y = lbl_27_rodata_7C;
    return v;
}
