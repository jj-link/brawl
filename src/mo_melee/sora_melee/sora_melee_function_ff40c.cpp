#pragma force_active on
typedef unsigned int u32;

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 pad0 : 4;
    u32 f : 2;
    u32 rest : 26;
};

extern "C" void fn_27_FF40C(Fn27Obj *p, u32 v)
{
    p->f = v;
}
