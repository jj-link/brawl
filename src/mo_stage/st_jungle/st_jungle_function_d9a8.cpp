#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned long flags;
} FlagObj;

extern "C" void fn_51_D9A8(FlagObj *obj)
{
    obj->flags &= ~0x00400000UL;
}
