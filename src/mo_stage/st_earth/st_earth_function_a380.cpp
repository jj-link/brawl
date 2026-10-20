#pragma force_active on
typedef unsigned long u32;

struct FnObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_66_A380(struct FnObj *obj)
{
    obj->flags |= 0x02000000;
}
