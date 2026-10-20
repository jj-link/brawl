#pragma force_active on
typedef struct {
    unsigned int a : 4;
    unsigned int f : 2;
    unsigned int b : 26;
} BF;

extern "C" void fn_40_28940(BF *p, unsigned int x) {
    p[2].f = x;
}
