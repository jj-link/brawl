#pragma force_active on
typedef unsigned int u32;

struct Fn27Bits {
    u32 hi : 10;
    u32 lo : 22;
};

struct Fn27Obj {
    char pad[8];
    Fn27Bits word;
};

extern "C" void fn_27_1A3C98(Fn27Obj* obj, u32 val)
{
    obj->word.hi = val;
}
