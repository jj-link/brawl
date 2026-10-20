#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int x : 8;
    int a : 4;
    unsigned int y : 20;
};

extern "C" int fn_66_A674(struct S *p)
{
    return p->a;
}
