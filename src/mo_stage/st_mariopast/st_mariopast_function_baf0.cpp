#pragma force_active on
typedef struct {
    unsigned int field0;
    unsigned int field1;
    unsigned int flags;
} FnObj;

extern "C" void fn_48_BAF0(FnObj *obj)
{
    obj->flags |= 0x2000;
}
