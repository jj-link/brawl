#pragma force_active on
typedef unsigned int u32;

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 flags : 3;
    u32 rest : 29;
};

extern "C" void fn_27_CC860(Fn27Obj* p, u32 v) {
    p->flags = v;
}
