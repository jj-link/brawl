#pragma force_active on
extern "C" {
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int f : 4;
    unsigned int rest : 28;
} Fn73Obj;

void fn_73_AD44(Fn73Obj *p, unsigned int v)
{
    p->f = v;
}
}
