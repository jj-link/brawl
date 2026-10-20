#pragma force_active on
extern const float lbl_27_rodata_BA8;

struct Holder {
    int pad0;
    int pad1;
    float x;
    float y;
};

struct Vec2 {
    float x;
    float y;
};

extern "C" {
void fn_27_8A554(Holder* p) {
    Vec2 tmp = { lbl_27_rodata_BA8, lbl_27_rodata_BA8 };
    p->x = tmp.x;
    p->y = tmp.y;
}
}
