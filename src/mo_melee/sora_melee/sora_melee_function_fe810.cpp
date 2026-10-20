#pragma force_active on
typedef unsigned int u32;

struct FooState {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 2;
        u32 b : 2;
        u32 c : 28;
    } flags;
};

extern "C" {
void fn_27_FE810(FooState* p, u32 v) {
    p->flags.b = v;
}
}
