#pragma force_active on
struct Bits {
    unsigned int pad[2];
    unsigned int a : 5;
    unsigned int b : 5;
    unsigned int c : 22;
};

extern "C" void fn_40_30B1C(Bits* p, unsigned int v) {
    p->b = v;
}
