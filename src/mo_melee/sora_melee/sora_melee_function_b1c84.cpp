#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_DB0;
extern const float lbl_27_rodata_DB4;
}

struct Vec3 {
    float x, y, z;

    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct State {
    char pad0[8];
    float* source;
    char padC[8];
    float a, b, c, d, e;
    Vec3 value;
    float last;
};

extern "C" void fn_27_B1C84(State* self) {
    float* p = self->source;
    self->a = p[0];
    self->b = p[1];
    self->c = p[2];
    self->d = p[3];
    self->e = p[4];

    Vec3 v(lbl_27_rodata_DB0, lbl_27_rodata_DB0, lbl_27_rodata_DB0);
    self->value = v;
    self->last = lbl_27_rodata_DB4;
}
