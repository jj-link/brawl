#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    u32 unk0;
    u32 unk4;
    u32 pad0 : 20;
    u32 field : 10;
    u32 pad1 : 2;
};

extern "C" {
void fn_27_1A4744(FnObj* p, u32 v) {
    p->field = v;
}
}
