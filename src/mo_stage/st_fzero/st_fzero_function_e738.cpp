#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int mode : 3;
    unsigned int rest : 29;
} FzeroObj;

extern "C" void fn_61_E738(FzeroObj *p, unsigned int v)
{
    p->mode = v;
}
