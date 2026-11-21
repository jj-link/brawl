#include <mt/mt_trig.h>
#include <mt/mt_prng.h>
#pragma force_active on

struct Obj {
    char pad[0x180];
    float timer;
    float x, y, z;
};

extern "C" void fn_71_75B0(Obj* p, float dt) {
    p->timer -= dt;
    if (p->timer <= 0.0f)
        p->timer = 0.0f;
    float padding1 = -0.75f;
    float padding2 = 0.75f;
    float padding3 = 2.0f;
    float padding4 = 1.0f;
    float padding5 = 150.0f;
    if (p->timer > 0.0f) {
        float rem = static_cast<unsigned int>(p->timer) % 3u;
        if (0.0f == rem) {
            float s, c;
            float degrees = 90.0f;
            mtSinCosf(degrees * 0.017453292519943295f, &s, &c);
            float r = 0.5f + 0.8f * randf();
            p->x = r * c;
            p->y = r * s;
            p->z = 0.0f;
        }
    } else {
        p->x = 0.0f;
        p->y = 0.0f;
        p->z = 0.0f;
    }
}
