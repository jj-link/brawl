#pragma force_active on
typedef struct {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int flags;
} FlagObj;

extern "C" void fn_27_1A167C(FlagObj *obj)
{
    obj->flags &= 0xFDFFFFFF;
}
