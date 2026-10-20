#pragma force_active on
struct S62 {
    char pad[8];
    unsigned int a : 6;
    unsigned int b : 3;
};

extern "C" void fn_62_616C(S62 *p, unsigned int v)
{
    p->b = v;
}
