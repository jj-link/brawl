#pragma force_active on
typedef unsigned int u32;

struct FieldWord {
    u32 unk0;
    u32 unk4;
    u32 hi : 4;
    u32 field : 2;
    u32 lo : 26;
};

extern "C" {
void fn_27_1A16B0(FieldWord* p, u32 v) {
    p->field = v;
}
}
