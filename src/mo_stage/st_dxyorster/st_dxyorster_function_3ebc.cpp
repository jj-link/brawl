#pragma force_active on
typedef unsigned int u32;

struct StObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_76_3EBC(StObj *obj)
{
    obj->flags |= 0x10000;
}
