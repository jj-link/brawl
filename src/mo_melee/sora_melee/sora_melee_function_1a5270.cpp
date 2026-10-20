#pragma force_active on
struct Bits {
    unsigned int hi : 6;
    unsigned int f : 3;
    unsigned int lo : 23;
};

extern "C" void fn_27_1A5270(Bits *p, unsigned int v)
{
    p[2].f = v;
}
