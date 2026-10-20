#pragma force_active on
struct Hdr {
    int a;
    int b;
    unsigned int hi : 4;
    unsigned int rest : 28;
};

extern "C" void fn_78_57F8(struct Hdr *p, unsigned int v)
{
    p->hi = v;
}
