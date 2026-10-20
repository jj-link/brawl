#pragma force_active on
extern "C" void fn_27_1A5824(unsigned int *p, unsigned int v) {
    struct Bits {
        unsigned int a : 4;
        unsigned int b : 4;
        unsigned int c : 24;
    };
    Bits *s = (Bits *)&p[2];
    s->b = v;
}
