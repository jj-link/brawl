#pragma force_active on
struct Bits {
    unsigned int hi : 12;
    unsigned int f : 6;
    unsigned int lo : 14;
};

struct Outer {
    unsigned int a;
    unsigned int b;
    Bits x;
};

extern "C" void fn_27_124E4C(Outer *p, unsigned int v)
{
    p->x.f = v;
}
