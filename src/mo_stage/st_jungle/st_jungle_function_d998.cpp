#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int flags;
} FnStruct51;

extern "C" void fn_51_D998(FnStruct51 *p)
{
    p->flags |= 0x400000;
}
