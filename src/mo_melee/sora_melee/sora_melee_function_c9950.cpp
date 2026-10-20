#pragma force_active on
struct Bits {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 1;
    unsigned int b : 1;
    unsigned int c : 1;
    unsigned int d : 1;
    unsigned int e : 1;
    unsigned int f : 1;
    unsigned int g : 3;
    unsigned int rest : 23;
};

extern "C" void fn_27_C9950(Bits *p, unsigned int v)
{
    p->g = v;
}
