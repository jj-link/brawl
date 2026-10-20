#pragma force_active on
struct Fld {
    unsigned int pad[2];
    unsigned int a : 5;
    unsigned int f : 5;
    unsigned int b : 22;
};

extern "C" void fn_27_19A268(Fld *p, unsigned int v)
{
    p->f = v;
}
