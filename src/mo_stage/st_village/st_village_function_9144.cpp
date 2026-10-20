#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int flags;
} FnObj70;

extern "C" {
void fn_70_9144(FnObj70 *obj)
{
    obj->flags |= 0x02000000;
}
}
