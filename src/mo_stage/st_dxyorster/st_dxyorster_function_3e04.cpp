#pragma force_active on
typedef struct FnObj
{
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" void fn_76_3E04(FnObj *obj)
{
    obj->flags &= ~0x10000;
}
