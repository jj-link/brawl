#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 10;
        u32 f : 5;
        u32 b : 17;
    } unk8;
};

extern "C" {
void fn_27_AAAD4(S* s, u32 v) {
    s->unk8.f = v;
}
}
