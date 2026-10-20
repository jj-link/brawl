#pragma force_active on
extern "C" {
typedef struct {
    unsigned int hi : 6;
    unsigned int rest : 26;
} Bits;

void fn_48_BAB0(unsigned int *p, unsigned int v) {
    Bits *b = (Bits *)&p[2];
    b->hi = v;
}
}
