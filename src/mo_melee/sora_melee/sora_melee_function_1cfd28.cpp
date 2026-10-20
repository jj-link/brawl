#pragma force_active on
typedef unsigned int u32;

struct FooHeader {
    char pad[8];
    u32 hi : 10;
    u32 f : 5;
    u32 lo : 17;
};

extern "C" void fn_27_1CFD28(FooHeader* p, u32 v) {
    p->f = v;
}
