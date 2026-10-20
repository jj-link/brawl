#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A1BFC_obj {
    u32 unk0;
    u32 unk4;
    u32 flags : 3;
    u32 rest : 29;
};

extern "C" void fn_27_1A1BFC(fn_27_1A1BFC_obj* p, u32 v) {
    p->flags = v;
}
