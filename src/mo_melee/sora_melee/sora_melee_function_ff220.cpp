#pragma force_active on
typedef unsigned int u32;

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 3;
        u32 f : 3;
        u32 b : 26;
    } unk8;
};

extern "C" {
void fn_27_FF220(fn27Obj* p, u32 v) {
    p->unk8.f = v;
}
}
