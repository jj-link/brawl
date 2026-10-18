#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" {
unsigned int fn_113_11E60(FnObj *p)
{
    return (p->flags >> 25) & 1;
}
}
