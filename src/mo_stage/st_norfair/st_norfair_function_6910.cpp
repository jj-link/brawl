#pragma force_active on
typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int x;
} S;

extern "C" int fn_54_6910(const S *p) {
    return (int)((p->x & 0x00F80000u) << 8) >> 28;
}
