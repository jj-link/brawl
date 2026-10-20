#pragma force_active on
struct Bits {
    unsigned int pad[2];
    unsigned int a : 6;
    unsigned int f : 3;
    unsigned int b : 23;
};

extern "C" void fn_27_1989DC(Bits *p, unsigned int v)
{
    p->f = v;
}
