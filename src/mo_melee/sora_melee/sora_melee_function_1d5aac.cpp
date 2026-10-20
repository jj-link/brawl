#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 5;
    u32 mid : 5;
    u32 lo : 22;
};

extern "C" void fn_27_1D5AAC(Obj* obj, u32 val)
{
    obj->mid = val;
}
