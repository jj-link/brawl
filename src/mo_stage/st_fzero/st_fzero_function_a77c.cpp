#pragma force_active on
struct FzBits {
    unsigned int w0;
    unsigned int w1;
    unsigned int hi : 4;
    unsigned int f : 2;
    unsigned int lo : 26;
};

extern "C" void fn_61_A77C(FzBits* p, unsigned int v)
{
    p->f = v;
}
