#include <mt/mt_trig.h>
#include <mt/mt_prng.h>
#pragma force_active on

struct Object { char padding[0x16C]; float timer, x, y, z; };
extern "C" void fn_51_126EC(void* object, float delta) {
    Object* self = (Object*)object;
    self->timer -= delta;
    if (self->timer <= 0.0f) self->timer = 0.0f;
    float padding = -0.4f;
    if (self->timer > 0.0f) {
        unsigned int t = (unsigned int)self->timer;
        float remainder = (float)(t % 3);
        if (0.0f == remainder) {
            float random = randf();
            float angle;
            if (random < 0.5f) {
                randf();
                angle = 0.0f;
            } else {
                angle = 180.0f * randf();
            }
            float sine, cosine;
            mtSinCosf(0.01745329238474369f * angle, &sine, &cosine);
            float scale = 0.5f + 0.8f * randf();
            self->x = scale * cosine;
            self->y = scale * sine;
            self->z = 0.0f;
        }
    } else {
        self->x = 0.0f;
        self->y = 0.0f;
        self->z = 0.0f;
    }
}
