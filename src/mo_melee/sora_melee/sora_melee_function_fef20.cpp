#pragma force_active on
typedef unsigned int u32;

struct FighterFlags {
    u32 unk0;
    u32 unk4;
    u32 mode : 2;
    u32 rest : 30;
};

extern "C" void fn_27_FEF20(FighterFlags* p, u32 v) {
    p->mode = v;
}
