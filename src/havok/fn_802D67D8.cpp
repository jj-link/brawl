#pragma force_active on
typedef struct {
    char pad[0x10];
    float x;
    float y;
    float z;
    float w;
} Src;

typedef struct {
    float x;
    float y;
    float z;
    float w;
} Dst;

extern "C" void fn_802D67D8(Src *src, Dst *dst) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
}
