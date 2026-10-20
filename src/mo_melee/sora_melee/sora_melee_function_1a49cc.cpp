#pragma force_active on
typedef unsigned int u32;

struct BitfieldHeader {
    u32 unk0;
    u32 unk4;
    u32 mode : 4;
    u32 rest : 28;
};

extern "C" {
void fn_27_1A49CC(BitfieldHeader* p, u32 v) {
    p->mode = v;
}
}
