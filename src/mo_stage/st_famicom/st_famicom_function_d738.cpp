#pragma force_active on
typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int pad:4;
    unsigned int f:2;
    unsigned int rest:26;
} S;

extern "C" {
void fn_68_D738(S *p, unsigned int v)
{
    p->f = v;
}
}
