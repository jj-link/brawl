#pragma force_active on
extern "C" int fn_122_201A0(float f)
{
    union {
        float f;
        unsigned int u;
    } v;
    int r;
    v.f = f;
    r = 1;
    if (((v.u >> 23) & 0xff) == 0xff) {
        r = 0;
    }
    return r;
}
