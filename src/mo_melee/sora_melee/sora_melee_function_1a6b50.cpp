#pragma force_active on
struct FnBits {
    unsigned int pad[2];
    unsigned int a : 10;
    unsigned int b : 22;
};

extern "C" void fn_27_1A6B50(FnBits *p, unsigned int v)
{
    p->a = v;
}
