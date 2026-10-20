#pragma force_active on
struct Fld {
    unsigned int pad[2];
    unsigned int a : 20;
    unsigned int b : 10;
    unsigned int c : 2;
};

extern "C" void fn_27_1A68C8(Fld *p, unsigned int v)
{
    p->b = v;
}
