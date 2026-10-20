#pragma force_active on
struct Bf {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int a : 12;
    unsigned int b : 6;
    unsigned int c : 14;
};

extern "C" void fn_40_1E580(Bf* p, unsigned int v) {
    p->b = v;
}
