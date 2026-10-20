#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int pad : 6;
    int f : 3;
};

extern "C" int fn_27_295F84(S* p);

int fn_27_295F84(S* p)
{
    return p->f;
}
