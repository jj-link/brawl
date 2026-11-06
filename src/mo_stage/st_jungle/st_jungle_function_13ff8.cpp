#pragma force_active on

extern "C" void mtSinCosf__FfPfPf(float, float*, float*);
extern "C" float randf__Fv();

struct Obj {
    char pad[0x16c];
    float timer;
    float x, y, z;
};

// Unresolved: the two constant-pool relocations do not reference
// lbl_51_rodata_238. Direct references produced a larger instruction diff.
extern "C" void fn_51_13FF8(void* a, float dt) {
    Obj* p = static_cast<Obj*>(a);
    p->timer -= dt;
    if (p->timer <= 0.0f)
        p->timer = 0.0f;
    if (p->timer > 0.0f) {
        float rem = static_cast<unsigned int>(p->timer) % 3u;
        if (0.0f == rem) {
            float s, c;
            float degrees = 90.0f;
            mtSinCosf__FfPfPf(degrees * 0.017453292519943295f, &s, &c);
            float r = 0.5f + 0.8f * randf__Fv();
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
