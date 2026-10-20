#pragma force_active on
struct Bits {
    unsigned int hi : 4;
    unsigned int f : 4;
    unsigned int lo : 24;
};

extern "C" void fn_52_7644(struct Bits *p, unsigned long v)
{
    p[2].f = v;
}
