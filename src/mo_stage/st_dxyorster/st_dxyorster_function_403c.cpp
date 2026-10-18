#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" {
unsigned int fn_76_403C(FnObj *p)
{
    return (p->flags >> 19) & 1;
}
}
