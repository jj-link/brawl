#pragma force_active on
struct fn_27_Obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_19BEF8(struct fn_27_Obj *p)
{
    p->flags &= ~0x02000000;
}
}
