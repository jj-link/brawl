#pragma force_active on
extern "C" {
typedef struct {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int f : 2;
    unsigned int b : 26;
} S;

void fn_70_903C(S *p, unsigned int v)
{
    p->f = v;
}
}
