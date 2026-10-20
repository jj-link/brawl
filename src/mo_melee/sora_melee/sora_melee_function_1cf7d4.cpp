#pragma force_active on
extern "C" {
struct FnObj27 {
    int unk0;
    int unk4;
    unsigned int flags;
};

void fn_27_1CF7D4(FnObj27 *p)
{
    p->flags &= ~0x10000u;
}
}
