#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int flags;
} FlagObj;

extern "C" {
void fn_67_50FC(FlagObj *obj)
{
    obj->flags |= 0x02000000;
}
}
