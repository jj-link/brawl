#pragma force_active on
typedef unsigned int u32;

struct FooObj {
    u32 pad[2];
    u32 hi : 3;
    u32 lo : 29;
};

extern "C" void fn_27_1A3068(FooObj* p, u32 v) {
    p->hi = v;
}
