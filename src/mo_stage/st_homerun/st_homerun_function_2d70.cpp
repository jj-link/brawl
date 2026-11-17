#pragma force_active on
#include <nw4r/math/math_arithmetic.h>

typedef unsigned char u8;

struct Item {
    u8 pad0[0x2c];
    u8 b2c;
};

struct Self {
    u8 pad0[0x1ec];
    Item* item;
    u8 pad1f0[0x18];
    float f208;
    u8 pad20c[0x378];
    float f584;
    float f588;
    float f58c;
    float f590;
    u8 pad594[0x3c];
    float f5d0;
};

extern "C" const float lbl_88_rodata_0[];
extern "C" void fn_27_28DE90(void*, float*);
extern "C" float getParamFloat__8BaseItemFUl(void*, unsigned long);

inline float clampValue(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" void fn_88_2D70(Self* self) {
    const float* c = lbl_88_rodata_0;
    Item* item = self->item;

    if (item == 0)
        return;
    if (((item->b2c >> 6) & 1) == 0)
        return;

    float params[3];
    params[0] = getParamFloat__8BaseItemFUl(item, 3);
    params[1] = getParamFloat__8BaseItemFUl(self->item, 4);
    params[2] = c[0];

    if (self->f590 > c[0]) {
        params[0] = c[36];
        fn_27_28DE90(self->item, &params[0]);
    }

    self->f588 = self->f584;
    self->f584 = clampValue(params[0], c[0], params[0]);

    if (self->f58c >= c[36]) {
        self->f584 = self->f5d0;
        self->f58c = self->f58c + self->f5d0;
    } else {
        float new58c = self->f58c + ((float)(double)self->f584 - self->f588);
        self->f58c = new58c;
        if (c[0] == self->f590) {
            if (new58c >= c[36]) {
                self->f584 = new58c - c[36];
                params[0] = c[36];
                fn_27_28DE90(self->item, &params[0]);
            }
        }
    }

    float p = self->f58c;
    if (p < c[36]) {
        self->f590 = c[0];
        self->f208 = clampValue(p / c[37], c[0], c[22]);
    } else if (p > c[2]) {
        self->f590 = c[22];
        self->f208 = c[22];
    } else {
        float v = clampValue((p - c[36]) / c[33], c[0], c[22]);
        self->f208 = c[22];
        self->f590 = v;
    }
}
