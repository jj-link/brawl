#pragma force_active on
struct Bits {
    unsigned int hi : 2;
    unsigned int rest : 30;
};

extern "C" void fn_27_C9734(void *p, unsigned int v) {
    Bits *b = (Bits *)((char *)p + 8);
    b->hi = v;
}
