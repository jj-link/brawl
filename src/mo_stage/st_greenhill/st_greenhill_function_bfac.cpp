#pragma force_active on
typedef struct FnObj {
    int field0;
    int field4;
    unsigned int flags;
} FnObj;

extern "C" {
void fn_72_BFAC(FnObj *obj)
{
    obj->flags |= 0x400000;
}
}
