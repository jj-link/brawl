#pragma force_active on
typedef unsigned int u32;

struct fn_27_295FF8_Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 pad : 5;
        u32 field : 5;
        u32 rest : 22;
    } unk8;
};

extern "C" {
void fn_27_295FF8(fn_27_295FF8_Obj* p, u32 v) {
    p->unk8.field = v;
}
}
