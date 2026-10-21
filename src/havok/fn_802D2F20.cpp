#pragma force_active on
typedef struct {
    char pad[0x30];
    float f0;
    float f1;
    float f2;
    float f3;
} Src;

typedef struct {
    float f0;
    float f1;
    float f2;
    float f3;
} Dst;

extern "C" void fn_802D2F20(Src* src, Dst* dst) {
    dst->f0 = src->f0;
    dst->f1 = src->f1;
    dst->f2 = src->f2;
    dst->f3 = src->f3;
}
