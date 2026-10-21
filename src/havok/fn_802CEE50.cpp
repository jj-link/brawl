#pragma force_active on
typedef struct Src {
    char pad[0x20];
    float v[4];
} Src;

extern "C" void fn_802CEE50(Src *src, float *dst)
{
    dst[0] = src->v[0];
    dst[1] = src->v[1];
    dst[2] = src->v[2];
    dst[3] = src->v[3];
}
