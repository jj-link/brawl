#pragma force_active on
struct FlagHolder {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_CC718(FlagHolder *p)
{
    p->flags &= ~0x00400000;
}
}
