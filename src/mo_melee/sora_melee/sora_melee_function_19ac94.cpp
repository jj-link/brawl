#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 pad0 : 4;
    u32 f : 2;
    u32 pad1 : 26;
};

extern "C" {
void fn_27_19AC94(Obj* p, u32 v) {
    p->f = v;
}
}
