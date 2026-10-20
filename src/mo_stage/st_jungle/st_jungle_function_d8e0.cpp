#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnState;

extern "C" void fn_51_D8E0(FnState *p)
{
    p->flags &= 0xFFBFFFFF;
}
