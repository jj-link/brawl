#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int flags;
} FnObj;

extern "C" void fn_54_69A4(FnObj *obj)
{
    obj->flags |= 0x00080000;
}
