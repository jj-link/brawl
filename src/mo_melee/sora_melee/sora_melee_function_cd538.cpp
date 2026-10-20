#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} Bits;

extern "C" void fn_27_CD538(Bits *p, unsigned int v) {
    p->b = v;
}
