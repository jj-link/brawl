#pragma force_active on
typedef unsigned int u32;

struct SetFlagObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_1E7F20(SetFlagObj *p)
{
    p->flags |= 0x80000;
}
}
