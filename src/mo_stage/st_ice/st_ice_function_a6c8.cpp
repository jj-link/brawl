#pragma force_active on
typedef struct {
    int pad[2];
    unsigned long flags;
} FnObj;

extern "C" void fn_62_A6C8(FnObj *obj)
{
    obj->flags &= ~0x00080000UL;
}
