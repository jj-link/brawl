#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

extern "C" {
void fn_51_D808(FnObj *obj)
{
    obj->flags |= 0x400000;
}
}
