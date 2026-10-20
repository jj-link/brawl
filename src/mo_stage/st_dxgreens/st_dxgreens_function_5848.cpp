#pragma force_active on
typedef struct {
    unsigned int field0;
    unsigned int field1;
    unsigned int flags;
} FnObj79;

extern "C" void fn_79_5848(FnObj79 *obj)
{
    obj->flags |= 0x2000;
}
