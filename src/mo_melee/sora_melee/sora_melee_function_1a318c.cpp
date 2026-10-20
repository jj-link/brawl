#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 pad : 6;
    u32 field : 6;
    u32 rest : 20;
};

extern "C" {
void fn_27_1A318C(Obj* o, u32 v)
{
    o->field = v;
}
}
