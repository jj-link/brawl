#pragma force_active on
typedef unsigned int u32;

struct FooFlags {
    u32 unk0;
    u32 unk4;
    u32 a : 14;
    u32 b : 7;
    u32 c : 11;
};

extern "C" void fn_27_14F3AC(FooFlags* p, u32 v) {
    p->b = v;
}
