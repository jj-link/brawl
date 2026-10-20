#pragma force_active on
struct Fld {
    unsigned int w0;
    unsigned int w1;
    unsigned int pad : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
};

extern "C" void fn_62_A5E4(Fld *p, unsigned int v)
{
    p->f = v;
}
