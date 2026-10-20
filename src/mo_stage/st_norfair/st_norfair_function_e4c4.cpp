#pragma force_active on
struct S54 {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
};

extern "C" void fn_54_E4C4(struct S54 *p, unsigned int v)
{
    p->b = v;
}
