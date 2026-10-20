#pragma force_active on
typedef unsigned int u32;

struct FooFlags {
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

struct FooObj {
    u32 unk0;
    u32 unk4;
    FooFlags flags;
};

extern "C" {
void fn_27_11BA88(FooObj* obj, u32 v)
{
    obj->flags.b = v;
}
}
