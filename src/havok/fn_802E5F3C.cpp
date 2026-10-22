#pragma force_active on
#pragma fp_contract on
struct Ctx {
    char pad[0xdc];
    float k;
    float x0;
    float x1;
    float x2;
    float x3;
};

extern "C" void fn_802E5F3C(Ctx* c, const float* v, float s)
{
    float t[4] __attribute__((aligned(16)));
    t[0] = s * v[0];
    t[1] = s * v[1];
    t[2] = s * v[2];
    t[3] = s * v[3];
    float k = c->k;
    c->x0 = k * t[0] + c->x0;
    c->x1 = k * t[1] + c->x1;
    c->x2 = k * t[2] + c->x2;
    c->x3 = k * t[3] + c->x3;
}
