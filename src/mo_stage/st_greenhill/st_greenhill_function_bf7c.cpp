#pragma force_active on
typedef struct {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int mode : 3;
    unsigned int rest : 29;
} FnObj;

extern "C" void fn_72_BF7C(FnObj *obj, unsigned int mode)
{
    obj->mode = mode;
}
