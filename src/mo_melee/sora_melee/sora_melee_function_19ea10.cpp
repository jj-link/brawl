#pragma force_active on
typedef unsigned int u32;

struct BitObj {
    u32 unk0;
    u32 unk4;
    u32 field : 6;
    u32 rest : 26;
};

extern "C" {
void fn_27_19EA10(BitObj* p, u32 v) {
    p->field = v;
}
}
