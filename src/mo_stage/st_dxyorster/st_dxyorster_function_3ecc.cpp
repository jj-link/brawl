#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int flags;
} FnObj;

extern "C" {
void fn_76_3ECC(FnObj *obj)
{
    obj->flags &= ~0x00010000;
}
}
