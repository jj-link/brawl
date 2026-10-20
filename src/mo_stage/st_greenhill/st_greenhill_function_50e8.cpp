#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" {
void fn_72_50E8(FnObj *obj)
{
    obj->flags |= 0x02000000;
}
}
