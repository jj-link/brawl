#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int flags;
} FnObj;

extern "C" void fn_49_6E68(FnObj *obj)
{
    obj->flags |= 0x02000000;
}
