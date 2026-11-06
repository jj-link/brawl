#include <mt/mt_trig.h>
#include <mt/mt_prng.h>
#pragma force_active on

struct Mansion {
    char pad[0x170];
    float timer;
    float vx;
    float vy;
    float vz;
};

extern "C" void fn_47_1EA8(Mansion* self, float delta) {
    self->timer -= delta;
    if (self->timer <= 0.0f)
        self->timer = 0.0f;

    float pool_padding = 0.875f;
    if (self->timer > 0.0f) {
        if (0.0f == (float)((unsigned int)self->timer % 3)) {
            float sinv;
            float cosv;
            float angle = 90.0f;
            mtSinCosf(angle * 0.017453292384743690f, &sinv, &cosv);
            float mag = 0.5f + 0.8f * randf();
            self->vx = mag * cosv;
            self->vy = mag * sinv;
            self->vz = 0.0f;
        }
    } else {
        self->vx = 0.0f;
        self->vy = 0.0f;
        self->vz = 0.0f;
    }
}
