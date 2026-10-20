#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags : 2;
    unsigned int rest : 30;
} FnObj;

extern "C" {
void fn_70_91B8(FnObj *p, unsigned int v)
{
    p->flags = v;
}
}
