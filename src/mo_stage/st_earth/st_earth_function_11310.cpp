#pragma force_active on
typedef struct {
    int w0;
    int w1;
    unsigned int pad : 3;
    unsigned int f : 3;
    unsigned int rest : 26;
} FnObj;

extern "C" {
void fn_66_11310(FnObj *p, unsigned int v)
{
    p->f = v;
}
}
