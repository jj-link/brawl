#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
} FnState;

void fn_72_53A4(FnState *p, unsigned int v)
{
    p->b = v;
}
}
