#pragma force_active on
struct Vec2 {
    float x, y;
};

extern "C" void fn_41_2354(Vec2*, float, float);
extern "C" float fn_41_10830(Vec2*);
extern "C" float fn_41_15A00(float, Vec2);
extern float lbl_41_rodata_D58;

extern "C" float fn_41_25BD0(float angle, Vec2 a, Vec2 b) {
    Vec2 v;
    fn_41_2354(&v, b.x - a.x, b.y - a.y);
    if (lbl_41_rodata_D58 == fn_41_10830(&v))
        return lbl_41_rodata_D58;
    return fn_41_15A00(angle, v);
}
