#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnStruct;

extern "C" void fn_72_BFBC(FnStruct *p)
{
    p->flags &= 0xFFBFFFFF;
}
