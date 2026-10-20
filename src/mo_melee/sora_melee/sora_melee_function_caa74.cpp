#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    u32 unk0;
    u32 unk4;
    u32 hi : 10;
    u32 f : 5;
    u32 lo : 17;
};

extern "C" {
void fn_27_CAA74(FnObj* p, u32 v) {
    p->f = v;
}
}
