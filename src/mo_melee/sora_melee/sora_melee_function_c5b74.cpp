#pragma force_active on
struct S8 {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};

extern "C" void fn_27_C5B74(S8 *p, unsigned int v)
{
    p->b = v;
}
