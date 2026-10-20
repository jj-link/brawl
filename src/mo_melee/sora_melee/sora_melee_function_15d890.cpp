#pragma force_active on
extern "C" const float lbl_27_rodata_1F70[3];

struct Vec2f {
    float x;
    float y;
};

struct Src {
    char pad[0xc];
    float f;
};

extern "C" {
Vec2f fn_27_15D890(const Src* p) {
    Vec2f v;
    v.y = p->f;
    v.x = lbl_27_rodata_1F70[0];
    return v;
}
}
