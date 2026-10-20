#pragma force_active on
typedef unsigned int u32;

struct BitfieldHolder {
    u32 unk0;
    u32 unk4;
    u32 top : 2;
    u32 rest : 30;
};

extern "C" void fn_27_1987C0(BitfieldHolder* p, u32 v) {
    p->top = v;
}
