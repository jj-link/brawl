#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_1A5750(Obj* obj)
{
    obj->flags &= ~0x00080000;
}
