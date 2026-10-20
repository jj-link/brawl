#pragma force_active on
typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int c : 6;
    unsigned int d : 26;
} S;

extern "C" void fn_48_BC34(S *p, unsigned int v)
{
    p->c = v;
}
