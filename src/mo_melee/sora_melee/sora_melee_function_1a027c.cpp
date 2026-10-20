#pragma force_active on
struct Bits {
    unsigned int pad[2];
    unsigned int hi : 6;
    unsigned int f : 3;
    unsigned int lo : 23;
};

extern "C" void fn_27_1A027C(Bits *p, unsigned int v)
{
    p->f = v;
}
