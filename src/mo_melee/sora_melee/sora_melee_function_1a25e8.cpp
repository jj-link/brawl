#pragma force_active on
typedef unsigned int u32;

struct fn27Obj {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_1A25E8(fn27Obj* obj)
{
    obj->flags &= 0xFFFEFFFF;
}
