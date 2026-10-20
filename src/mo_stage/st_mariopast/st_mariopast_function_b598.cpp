#pragma force_active on
extern "C" {
typedef struct {
    int w0;
    int w1;
    unsigned int f : 9;
    unsigned int rest : 23;
} FnBits;

void fn_48_B598(FnBits *p, unsigned int v)
{
    p->f = v;
}
}
