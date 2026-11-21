#include <types.h>
#include <revolution/OS/OSFastCast.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" const float lbl_43_rodata_0[];
extern "C" float fn_801622C4(float);
extern void* g_gfSceneRoot;

class Unk {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float getValue();
    virtual void v7();
};

struct Data {
    char pad[0x18];
    float unk18;
    float unk1C;
    float unk20;
};

struct Stage {
    char pad[0x98];
    Data* data;
    char padA0[0x4C];
    unsigned char unkE8;
};

static inline float calculate(float v, const float* c) {
    float t = v / c[1];
    t = nw4r::math::FSelect(t - c[0], t, c[0]);
    t = nw4r::math::FSelect(t - c[2], c[2], t);
    return c[3] * t;
}

static inline float position(float v, float divisor, float base, float scale, float lo, float hi) {
    float t = v / divisor;
    t = nw4r::math::FSelect(t - lo, t, lo);
    t = nw4r::math::FSelect(t - hi, hi, t);
    return base + scale * t;
}

extern "C" void fn_43_688(Stage* self) {
    const float* c = lbl_43_rodata_0;
    Data* data = self->data;
    if (data != NULL) {
        float var = c[0];
        void* obj = *(void**)((char*)g_gfSceneRoot + 0x54);
        if (obj != NULL) {
            var = ((Unk*)obj)->getValue();
        }
        if (var >= c[0] && var <= c[1]) {
            unsigned short angle = (unsigned short)calculate(var, c);
            (void)fn_801622C4(c[4] * __OSu16tof32(&angle));
            data->unk18 = c[9];
            data->unk1C = position(var, c[1], c[7], c[8], c[0], c[2]);
            data->unk20 = c[0];
            self->unkE8 = 1;
        } else {
            data->unk18 = c[5];
            data->unk1C = c[0];
            data->unk20 = c[0];
        }
    }
}
