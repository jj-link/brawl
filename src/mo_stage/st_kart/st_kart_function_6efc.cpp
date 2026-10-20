#pragma force_active on
struct Bits {
    unsigned long pad[2];
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
};

extern "C" void fn_49_6EFC(Bits *p, unsigned long v) {
    p->b = v;
}
