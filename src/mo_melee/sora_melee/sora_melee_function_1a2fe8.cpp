#pragma force_active on
struct Bits {
    unsigned int hi : 12;
    unsigned int f : 6;
    unsigned int lo : 14;
};

extern "C" void fn_27_1A2FE8(Bits *p, unsigned int v)
{
    ((Bits *)((char *)p + 8))->f = v;
}
