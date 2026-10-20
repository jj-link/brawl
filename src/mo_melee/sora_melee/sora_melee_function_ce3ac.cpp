#pragma force_active on
struct ClearBitObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_CE3AC(ClearBitObj* p)
{
    p->flags &= ~0x10000;
}
}
