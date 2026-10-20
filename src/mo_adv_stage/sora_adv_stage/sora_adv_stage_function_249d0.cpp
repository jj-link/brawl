#pragma force_active on
struct BitS {
    int w0;
    int w1;
    unsigned int f : 2;
    unsigned int rest : 30;
};

extern "C" void fn_40_249D0(BitS* p, unsigned int v) {
    p->f = v;
}
