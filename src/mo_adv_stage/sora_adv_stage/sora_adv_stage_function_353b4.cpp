#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" const float lbl_40_rodata_6A0;
extern "C" float lbl_27_data_547E0;

struct Params {
    char pad[0x28];
    float speed;
};

struct Object {
    char pad0[0x150];
    Params* params;
    char pad154[0x1C];
    float x;
    float y;
    float threshold;
    float acceleration;
    float speed;
    float count;
};

static inline float absolute(float x) {
    return (float)(double)nw4r::ut::Abs(x);
}

extern "C" void fn_40_353B4(Object* self) {
    float speed = self->speed;
    self->count = lbl_40_rodata_6A0;
    float x = self->x;
    float y = self->y;

    for (;;) {
        float oldSpeed = speed;
        float threshold = absolute(self->threshold);
        bool less = absolute(x) < threshold;

        if (less) {
            speed += self->acceleration;
        } else if (absolute(y) < threshold) {
            speed -= self->acceleration;
        } else if (y > lbl_40_rodata_6A0) {
            speed = self->params->speed;
        } else {
            speed = -self->params->speed;
        }

        x += speed;
        y -= speed;

        if (oldSpeed < lbl_40_rodata_6A0 &&
            speed >= lbl_40_rodata_6A0) {
            return;
        }

        if (oldSpeed > lbl_40_rodata_6A0 &&
            speed <= lbl_40_rodata_6A0) {
            return;
        }

        float absSpeed = absolute(speed);
        if (absolute(y) < absSpeed) {
            return;
        }

        float delta = lbl_27_data_547E0;
        self->count += delta;
    }
}
