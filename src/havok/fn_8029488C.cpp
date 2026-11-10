#pragma force_active on
struct V0 { float x[4]; };
struct V1 { float x[4]; };
struct V2 { float x[4]; };
struct V3 { float x[4]; };
extern "C" void fn_8029488C(const V0* a, const V1* b, V2* c, V3* d) {
    float s0 = c->x[0] + a->x[0];
    float s1 = c->x[1] + a->x[1];
    float s2 = c->x[2] + a->x[2];
    float s3 = c->x[3] + a->x[3];
    c->x[1] = s1;
    c->x[2] = s2;
    c->x[3] = s3;
    c->x[0] = s0;
    d->x[0] = d->x[0] + b->x[0];
    d->x[1] = d->x[1] + b->x[1];
    d->x[2] = d->x[2] + b->x[2];
    d->x[3] = d->x[3] + b->x[3];
}