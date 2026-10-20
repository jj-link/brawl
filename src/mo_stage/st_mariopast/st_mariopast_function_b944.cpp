#pragma force_active on
struct S {
    int pad[2];
    unsigned int f : 7;
    unsigned int g : 25;
};

extern "C" void fn_48_B944(struct S *p, unsigned int v)
{
    p->f = v;
}
