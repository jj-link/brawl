#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int x : 8;
    unsigned int f : 4;
    unsigned int rest : 20;
} S;

extern "C" void fn_70_932C(S *p, unsigned int v)
{
    p->f = v;
}
