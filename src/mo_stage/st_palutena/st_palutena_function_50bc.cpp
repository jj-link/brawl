#pragma force_active on
extern "C" {
typedef struct {
    unsigned int pad[2];
    unsigned int mode : 2;
    unsigned int rest : 30;
} FnObj;

void fn_67_50BC(FnObj *obj, unsigned int val)
{
    obj->mode = val;
}
}
