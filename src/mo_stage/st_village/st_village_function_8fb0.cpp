#pragma force_active on

extern "C" {
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int f : 2;
    unsigned int b : 28;
} S;

void fn_70_8FB0(S *p, unsigned int v)
{
    p->f = v;
}
}
