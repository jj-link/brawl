#pragma force_active on
typedef struct {
    int pad0;
    int pad4;
    unsigned int flags;
} StFlagObj;

extern "C" void fn_54_6838(StFlagObj *obj)
{
    obj->flags &= ~0x02000000u;
}
