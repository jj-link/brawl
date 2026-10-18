#pragma force_active on
struct S { unsigned int a[4]; };

extern "C" unsigned int fn_119_9A84(S *const *p, unsigned int i)
{
    return p[3]->a[i];
}