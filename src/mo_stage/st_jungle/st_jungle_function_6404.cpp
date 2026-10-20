#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int top : 2;
    unsigned int rest : 30;
} FnObj;

extern "C" void fn_51_6404(FnObj *obj, unsigned int v)
{
    obj->top = v;
}
