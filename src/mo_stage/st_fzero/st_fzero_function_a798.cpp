#pragma force_active on
struct Fld {
    unsigned int a;
    unsigned int b;
    unsigned int hi : 4;
    unsigned int rest : 28;
};

extern "C" void fn_61_A798(struct Fld *p, unsigned int v)
{
    p->hi = v;
}
