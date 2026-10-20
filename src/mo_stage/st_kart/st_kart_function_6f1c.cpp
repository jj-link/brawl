#pragma force_active on
extern "C" {
typedef struct FnObj {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int flags;
} FnObj;

void fn_49_6F1C(FnObj *obj)
{
    obj->flags |= 0x00080000;
}
}
