#pragma force_active on
struct S54 {
    unsigned int pad[2];
    unsigned int hi : 8;
    unsigned int f : 4;
    unsigned int lo : 20;
};

extern "C" void fn_54_E53C(struct S54 *p, unsigned int v)
{
    p->f = v;
}
