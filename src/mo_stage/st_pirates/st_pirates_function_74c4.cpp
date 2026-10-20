#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int flag : 2;
    unsigned int rest : 30;
} Obj;

extern "C" void fn_52_74C4(Obj *p, unsigned int v)
{
    p->flag = v;
}
