#pragma force_active on
extern "C" {
struct S8 {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};
void fn_62_F070(unsigned int *p, unsigned int v)
{
    S8 *s = (S8 *)((char *)p + 8);
    s->b = v;
}
}
