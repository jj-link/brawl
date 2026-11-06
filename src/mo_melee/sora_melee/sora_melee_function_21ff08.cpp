#pragma force_active on
struct Vec2 { float x, y; Vec2(float a, float b) : x(a), y(b) {} };
extern const float lbl_27_rodata_3318;
struct Obj { Vec2 vec[16]; int ints[16]; int end; };
extern "C" void fn_27_21FF08(Obj* p) {
    for (int i = 0; i < 16; i++) {
        p->vec[i] = Vec2(lbl_27_rodata_3318, lbl_27_rodata_3318);
        p->ints[i] = 0;
    }
    p->end = 0;
}