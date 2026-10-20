#pragma force_active on
typedef unsigned int u32;

struct Obj40 {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_40_24A20(Obj40* obj)
{
    obj->flags &= ~0x02000000;
}
}
