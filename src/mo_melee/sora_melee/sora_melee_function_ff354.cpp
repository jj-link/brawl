#pragma force_active on
typedef unsigned int u32;

struct fn_27_FF354_obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 hi : 6;
        u32 f : 3;
        u32 lo : 23;
    } unk8;
};

extern "C" {
void fn_27_FF354(fn_27_FF354_obj* p, u32 v) {
    p->unk8.f = v;
}
}
