#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 5;
        u32 b : 5;
        u32 c : 22;
    } flags;
};

extern "C" {
void fn_27_19A4E8(Obj* p, u32 v) {
    p->flags.b = v;
}
}
