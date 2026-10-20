#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" {
int fn_51_6738(FnObj *p)
{
    return (int)((p->flags & 0x0E000000) << 4) >> 30;
}
}
