#pragma force_active on
extern "C" {
typedef struct FnObj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
} FnObj;

void fn_27_1E7F30(FnObj *obj)
{
    obj->flags &= ~0x80000u;
}
}
