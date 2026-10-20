#pragma force_active on
struct Bits {
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int rest : 28;
};

extern "C" void fn_63_11F74(unsigned int *p, unsigned int v) {
    Bits *s = (Bits *)(p + 2);
    s->b = v;
}
