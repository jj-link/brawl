#pragma force_active on
typedef struct {
    int pad[2];
    unsigned long flags;
} FnObj74;

extern "C" void fn_74_68CC(FnObj74 *p)
{
    p->flags &= 0xFDFFFFFFUL;
}
