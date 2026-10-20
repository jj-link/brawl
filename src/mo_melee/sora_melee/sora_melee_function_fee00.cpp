#pragma force_active on
struct FeeObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_FEE00(FeeObj* p)
{
    p->flags &= ~0x2000;
}
}
