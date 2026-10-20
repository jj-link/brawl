#pragma force_active on
struct S8 {
    unsigned int pad[2];
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 20;
};

extern "C" void fn_27_122B48(S8 *p, unsigned int v)
{
    p->b = v;
}
