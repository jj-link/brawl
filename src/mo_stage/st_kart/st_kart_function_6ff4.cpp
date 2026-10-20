#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

void fn_49_6FF4(FnObj *obj)
{
    obj->flags &= ~0x80000u;
}
}
