#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int pad_bits : 3;
    unsigned int bits : 3;
    unsigned int rest : 26;
};

extern "C" void fn_27_1A7510(S *p, unsigned int value) {
    p->bits = value;
}
