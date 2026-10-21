#pragma force_active on

typedef struct {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int pad : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
} St;

extern "C" void fn_66_A558(St *p, unsigned int v)
{
    p->f = v;
}
