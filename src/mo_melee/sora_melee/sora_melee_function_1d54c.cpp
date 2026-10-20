#pragma force_active on
typedef unsigned int u32;

struct fn27_obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 4;
        u32 b : 2;
        u32 c : 26;
    } flags;
};

extern "C" {
void fn_27_1D54C(fn27_obj* p, u32 v)
{
    p->flags.b = v;
}
}
