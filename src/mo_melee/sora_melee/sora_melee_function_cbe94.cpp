#pragma force_active on
struct S {
    int a;
    int b;
    unsigned : 12;
    unsigned v : 1;
    unsigned : 19;
};

extern "C" int fn_27_CBE94(struct S *p)
{
    return p->v;
}
