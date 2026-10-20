#pragma force_active on
typedef unsigned int u32;

struct Fn27Bits {
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
};

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    Fn27Bits flags;
};

extern "C" void fn_27_199684(Fn27Obj* obj, u32 value)
{
    obj->flags.b = value;
}
