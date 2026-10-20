#pragma force_active on
typedef unsigned int u32;

struct Fn27Obj {
    u32 pad[2];
    u32 hi : 5;
    u32 rest : 27;
};

extern "C" void fn_27_1A2058(Fn27Obj* obj, u32 value)
{
    obj->hi = value;
}
