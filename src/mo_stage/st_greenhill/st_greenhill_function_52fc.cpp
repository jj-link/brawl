#pragma force_active on
struct FnState {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_72_52FC(struct FnState *p)
{
    p->flags |= 0x80000;
}
}
