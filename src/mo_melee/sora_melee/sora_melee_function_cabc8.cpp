#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int flags;
} FnObj;

extern "C" void fn_27_CABC8(FnObj *p)
{
    p->flags |= 0x2000;
}
