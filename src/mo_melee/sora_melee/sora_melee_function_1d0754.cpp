#pragma force_active on
typedef unsigned int u32;

struct FieldObj {
    u32 unk0;
    u32 unk4;
    u32 kind : 4;
    u32 rest : 28;
};

extern "C" void fn_27_1D0754(FieldObj* p, u32 v) {
    p->kind = v;
}
