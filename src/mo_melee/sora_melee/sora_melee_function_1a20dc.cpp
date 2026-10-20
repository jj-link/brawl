#pragma force_active on
typedef unsigned int u32;

struct FieldObj {
    u32 unk0;
    u32 unk4;
    u32 hi : 10;
    u32 mid : 5;
    u32 lo : 17;
};

extern "C" void fn_27_1A20DC(FieldObj* p, u32 v) {
    p->mid = v;
}
