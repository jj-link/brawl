#pragma force_active on
struct FnObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_27_CFD1C(struct FnObj *p)
{
    p->flags |= 0x400;
}
