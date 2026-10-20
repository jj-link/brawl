#pragma force_active on
struct FnBits {
    unsigned int a : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
};

extern "C" void fn_27_19C8AC(FnBits *p, unsigned int v)
{
    FnBits *q = (FnBits *)((char *)p + 8);
    q->f = v;
}
