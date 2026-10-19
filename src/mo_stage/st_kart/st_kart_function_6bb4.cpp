#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 field0;
    u32 field4;
    u32 flags;
};

extern "C" u32 fn_49_6BB4(struct Obj *obj)
{
    return (obj->flags >> 25) & 1;
}
