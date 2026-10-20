#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int flags;
} FnObj;

extern "C" {
void fn_72_53D4(FnObj *obj)
{
    obj->flags &= ~0x80000u;
}
}
