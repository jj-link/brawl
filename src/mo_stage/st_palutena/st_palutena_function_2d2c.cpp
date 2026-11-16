#include <mt/mt_trig.h>
#include <mt/mt_prng.h>
#pragma force_active on

struct Obj {
    char pad[0x170];
    float timer, x, y, z;
};

extern "C" void fn_67_2D2C(void* a, float dt) {
    Obj* p = static_cast<Obj*>(a);
    p->timer -= dt;
    if (p->timer <= 0.0f)
        p->timer = 0.0f;
    float p1 = 1.0f;
    float p2 = 5.0f;
    float p3 = 10.0f;
    float p4 = 4.0f;
    float p5 = 0.001f;
    float p6 = -6.0f;
    float p7 = 6.0f;
    float p8 = 2.5f;
    if (p->timer > 0.0f) {
        float rem = (float)((unsigned int)p->timer % 3u);
        if (0.0f == rem) {
            float spC, sp8;
            float angle = 90.0f;
            mtSinCosf(0.01745329238474369f * angle, &spC, &sp8);
            float t = 0.3f + 0.4f * randf();
            p->x = 0.75f * (t * sp8);
            p->y = t * spC;
            p->z = 0.0f;
        }
    } else {
        p->x = 0.0f;
        p->y = 0.0f;
        p->z = 0.0f;
    }
}