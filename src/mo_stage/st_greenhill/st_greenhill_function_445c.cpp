#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" u32 fn_72_445C(struct FnObj *obj)
{
    return (obj->flags >> 25) & 1;
}
