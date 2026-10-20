#pragma force_active on
typedef unsigned int u32;

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 6;
    u32 rest : 26;
};

extern "C" void fn_27_19B530(Fn27Obj* obj, u32 val)
{
    obj->hi = val;
}
