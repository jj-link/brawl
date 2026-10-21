#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_27A4;
extern const float lbl_27_rodata_27A0;
}

struct Vec2 {
    float x, y;

    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
};

struct Object {
    char pad[8];
    Vec2 position;
    Vec2 a, b, c, d;
    int unk30;
    int type;
};

extern "C" void fn_27_1DBBA0(Object* self, int type, const Vec2* position) {
    self->a = Vec2(lbl_27_rodata_27A4, lbl_27_rodata_27A4);
    self->b = Vec2(lbl_27_rodata_27A0, lbl_27_rodata_27A0);
    self->c = Vec2(lbl_27_rodata_27A4, lbl_27_rodata_27A4);
    self->d = Vec2(lbl_27_rodata_27A0, lbl_27_rodata_27A0);
    self->position = *position;
    self->type = type;

    switch (type) {
    case 0:
        break;
    case 1:
        self->b = Vec2(lbl_27_rodata_27A4, lbl_27_rodata_27A4);
        break;
    }
}
