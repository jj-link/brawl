#pragma force_active on
struct Bits {
    unsigned int w0;
    unsigned int w1;
    unsigned int f : 5;
    unsigned int rest : 27;
};

extern "C" {
void fn_27_1CF784(Bits* p, unsigned int v) {
    p->f = v;
}
}
