#pragma force_active on
typedef struct {
    int field0;
    int field1;
    unsigned int flags;
} FnState;

extern "C" void fn_51_6444(FnState *p)
{
    p->flags |= 0x02000000;
}
