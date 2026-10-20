#pragma force_active on
typedef struct {
    unsigned int a[2];
    unsigned int hi : 4;
    unsigned int lo : 28;
} S;

extern "C" void fn_74_6B6C(S *p, unsigned int v) {
    p->hi = v;
}
