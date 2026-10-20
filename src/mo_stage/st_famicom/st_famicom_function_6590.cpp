#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" void fn_68_6590(FnObj *p)
{
    p->flags &= ~0x80000;
}
