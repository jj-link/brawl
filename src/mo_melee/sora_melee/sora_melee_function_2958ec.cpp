#pragma force_active on
struct Bits {
    unsigned int a : 10;
    unsigned int mid : 5;
    unsigned int c : 17;
};

struct Wrap {
    unsigned int pad[2];
    Bits b;
};

extern "C" void fn_27_2958EC(Wrap *p, unsigned int v) {
    p->b.mid = v;
}
