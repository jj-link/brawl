#pragma force_active on
struct Foo {
    int a;
    int b;
    unsigned int f0 : 4;
    unsigned int f1 : 2;
    unsigned int rest : 26;
};

extern "C" void fn_74_69F0(struct Foo *p, unsigned int v)
{
    p->f1 = v;
}
