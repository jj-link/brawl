#pragma force_active on
extern "C" {
typedef struct FnObj {
    int pad0;
    int pad1;
    unsigned int flag : 2;
    unsigned int rest : 30;
} FnObj;

void fn_79_5AEC(FnObj *obj, unsigned int value)
{
    obj->flag = value;
}
}
