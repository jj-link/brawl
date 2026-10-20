#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 6;
    u32 lo : 26;
};

extern "C" {
void fn_27_122BE0(Obj* p, u32 v) {
    p->hi = v;
}
}
