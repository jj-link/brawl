#pragma force_active on
typedef unsigned int u32;

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 6;
    u32 rest : 26;
};

extern "C" {
void fn_27_1A2F64(Fn27Obj* p, u32 v)
{
    p->hi = v;
}
}
