#pragma force_active on
struct BF {
    unsigned int hi : 2;
    unsigned int rest : 30;
};

extern "C" void fn_27_C9A88(void *p, unsigned int v) {
    BF *b = (BF *)((char *)p + 8);
    b->hi = v;
}
