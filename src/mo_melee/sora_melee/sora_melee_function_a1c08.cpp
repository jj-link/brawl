#pragma force_active on
typedef unsigned int u32;

struct fn_27_A1C08_obj {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_A1C08(fn_27_A1C08_obj* obj)
{
    obj->flags |= 0x10000;
}
