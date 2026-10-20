#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int flag : 2;
    unsigned int rest : 30;
} Obj;

extern "C" void fn_67_4F2C(Obj *p, unsigned int v)
{
    p->flag = v;
}
