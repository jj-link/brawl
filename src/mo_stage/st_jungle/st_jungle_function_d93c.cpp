#pragma force_active on
extern "C" {
struct S {
    unsigned int a;
    unsigned int b;
    unsigned int pad : 6;
    unsigned int c : 3;
    unsigned int d : 23;
};
void fn_51_D93C(struct S *p, unsigned int v)
{
    p->c = v;
}
}
