#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int c;
};

extern "C" int fn_40_30B0C(S* p) {
    unsigned int t = (p->c << 5) | (p->c >> 27);
    return (int)(t & 0xFC000000u) >> 27;
}
