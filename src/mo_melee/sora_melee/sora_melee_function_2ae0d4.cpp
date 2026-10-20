#pragma force_active on
typedef unsigned int u32;

struct FooWord {
    u32 unk0;
    u32 unk4;
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" void fn_27_2AE0D4(FooWord* p, u32 v) {
    p->b = v;
}
