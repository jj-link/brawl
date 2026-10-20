#pragma force_active on
typedef unsigned int u32;

struct fn_27_FEF60_obj {
    char pad[0x8];
    u32 flags;
};

extern "C" void fn_27_FEF60(fn_27_FEF60_obj* obj)
{
    obj->flags |= 0x02000000;
}
