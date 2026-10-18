#pragma force_active on
typedef struct FnObj {
    unsigned int pad[2];
    unsigned int flags;
} FnObj;

extern "C" void fn_63_ADB8(FnObj *obj)
{
    obj->flags &= 0xFDFFFFFF;
}
