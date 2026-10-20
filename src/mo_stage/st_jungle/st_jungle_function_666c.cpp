#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int flags;
} FnObj;

extern "C" {
void fn_51_666C(FnObj *p)
{
    p->flags |= 0x02000000;
}
}
