#pragma force_active on
typedef unsigned int u32;

struct FieldObj {
    u32 unk0;
    u32 unk4;
    u32 f_hi : 4;
    u32 f_mid : 4;
    u32 f_low : 24;
};

extern "C" void fn_27_1CFE1C(FieldObj* p, u32 v) {
    p->f_mid = v;
}
