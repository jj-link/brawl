#pragma force_active on
typedef struct {
    unsigned int a : 8;
    unsigned int f : 4;
    unsigned int b : 20;
} Bits;

extern "C" void fn_78_58A4(Bits *p, unsigned int v) {
    Bits *q = (Bits *)((char *)p + 8);
    q->f = v;
}
