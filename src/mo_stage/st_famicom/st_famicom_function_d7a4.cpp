#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned long flags;
} FlagObj;

extern "C" void fn_68_D7A4(FlagObj *obj)
{
    obj->flags &= ~0x80000UL;
}
