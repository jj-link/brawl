#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 30;
} S;

extern "C" void fn_74_6AC8(S *p, unsigned int v)
{
    p->a = v;
}
