#pragma force_active on
#include <nw4r/math/math_arithmetic.h>
extern "C" {
extern const float lbl_51_rodata_A0[];
}
struct Obj {
    char pad[0x150];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[0x3C];
    unsigned char* ptr;
    char pad198[0xC];
    float amount;
};
inline float clampf(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}
extern "C" void fn_51_B55C(Obj* self, float delta) {
    const float* c = lbl_51_rodata_A0;
    self->timer -= delta;
    if (self->timer < c[1])
        self->timer = c[1];
    switch (self->state) {
    case 0:
        self->state = 1;
        break;
    case 1:
        if (*self->ptr != 0) {
            self->state = 3;
            self->timer = c[2];
        }
        break;
    case 3: {
        float value = c[0] - self->timer / c[2];
        float t = clampf(value, c[3], c[0]);
        self->amount = c[0] - t;
        if (c[0] == t)
            self->state = 4;
        break;
    }
    case 4:
        if (*self->ptr == 0) {
            self->state = 5;
            self->timer = c[2];
        }
        break;
    case 5: {
        float value = c[0] - self->timer / c[2];
        float t = clampf(value, c[3], c[0]);
        self->amount = t;
        if (c[0] == t)
            self->state = 0;
        break;
    }
    }
}