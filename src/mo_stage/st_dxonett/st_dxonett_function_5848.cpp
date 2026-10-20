#pragma force_active on
typedef struct FnObj
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
} FnObj;

extern "C" void fn_78_5848(FnObj *obj)
{
    obj->flags &= ~0x00080000;
}
