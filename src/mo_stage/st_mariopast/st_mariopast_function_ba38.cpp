#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" void fn_48_BA38(FnObj *obj)
{
    obj->flags &= ~0x2000u;
}
