#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int flags;
} FlagObj;

extern "C" void fn_79_5780(FlagObj *obj)
{
    obj->flags |= 0x2000;
}
