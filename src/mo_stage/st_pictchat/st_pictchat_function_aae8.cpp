#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj73;

extern "C" void fn_73_AAE8(FnObj73 *obj)
{
    obj->flags &= ~0x02000000;
}
