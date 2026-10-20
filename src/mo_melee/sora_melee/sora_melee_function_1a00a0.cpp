#pragma force_active on
typedef unsigned int u32;

struct SetFlagObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1A00A0(SetFlagObj* obj)
{
    obj->flags |= 0x02000000;
}
