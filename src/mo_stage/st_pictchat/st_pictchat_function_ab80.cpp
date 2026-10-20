#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" void fn_73_AB80(FnObj *p)
{
    p->flags &= ~0x00400000u;
}
