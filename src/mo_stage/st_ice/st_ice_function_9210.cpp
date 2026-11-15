#include <mt/mt_prng.h>
#include <mt/mt_trig.h>
#pragma force_active on

struct S {
    char pad[0x168];
    float timer, x, y, z;
};

extern "C" void fn_62_9210(void* a, float dt) {
    S* s = (S*)a;
    float t = s->timer - dt;
    s->timer = t;
    if (t <= 0.0f)
        s->timer = 0.0f;

    float padding1 = 60.0f;
    float padding2 = 4.0f;
    float padding3 = 2.0f;
    float padding4 = 360.0f;
    if (s->timer > 0.0f) {
        unsigned int n = (unsigned int)s->timer;
        unsigned int rem = n % 3;
        float m = (float)rem;
        if (0.0f == m) {
            float sinv, cosv;
            mtSinCosf(
                0.01745329238474369f * (360.0f * randf()),
                &sinv,
                &cosv
            );
            float mag = 0.5f + 0.8f * randf();
            s->x = mag * cosv;
            s->y = mag * sinv;
            s->z = 0.0f;
        }
    } else {
        s->x = 0.0f;
        s->y = 0.0f;
        s->z = 0.0f;
    }
}