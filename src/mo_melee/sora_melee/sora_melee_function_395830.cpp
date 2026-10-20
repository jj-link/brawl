#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 f : 4;
        u32 rest : 28;
    } unk8;
};

extern "C" {
void fn_27_395830(Obj* p, u32 v) {
    p->unk8.f = v;
}
}
