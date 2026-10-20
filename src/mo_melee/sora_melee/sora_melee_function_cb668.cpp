#pragma force_active on
struct FnObj27 {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_27_CB668(FnObj27 *p)
{
    p->flags &= ~0x400;
}
