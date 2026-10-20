#pragma force_active on
typedef struct {
    int pad0;
    int pad4;
    unsigned int flags;
} FnObj;

extern "C" void fn_27_19E8DC(FnObj *p)
{
    p->flags |= 0x10000;
}
