#pragma force_active on
struct S {
    int pad[2];
    unsigned int a : 4;
    int f : 2;
};

extern "C" int fn_47_4BF4(S *p)
{
    return p->f;
}
