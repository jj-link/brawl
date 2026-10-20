#pragma force_active on
typedef struct {
    unsigned int hi : 4;
    unsigned int rest : 28;
} Fn71Word;

extern "C" void fn_71_A184(unsigned char *self, unsigned int v) {
    Fn71Word *p = (Fn71Word *)(self + 8);
    p->hi = v;
}
