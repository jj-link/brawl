#pragma force_active on
#pragma fp_contract on

struct Foo {
    float pad[55];
    float s;
    float v[4];
};

extern "C" void fn_802E44A4(Foo *p, const float *a)
{
    float s = p->s;
    p->v[0] = s * a[0] + p->v[0];
    p->v[1] = s * a[1] + p->v[1];
    p->v[2] = s * a[2] + p->v[2];
    p->v[3] = s * a[3] + p->v[3];
}
