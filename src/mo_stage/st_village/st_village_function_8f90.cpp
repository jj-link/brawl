#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int flag : 2;
} FlagObj;

extern "C" void fn_70_8F90(FlagObj *obj, unsigned int value)
{
    obj->flag = value;
}
