#pragma force_active on
typedef struct {
    int pad0;
    int pad4;
    unsigned int flags;
} FnObj;

extern "C" void fn_72_4F84(FnObj *p)
{
    p->flags &= ~0x02000000u;
}
