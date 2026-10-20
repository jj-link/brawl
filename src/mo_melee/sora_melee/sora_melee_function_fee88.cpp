#pragma force_active on
typedef unsigned int u32;

struct FeeSub {
    u32 pad[2];
    u32 hi : 5;
    u32 field : 5;
    u32 lo : 22;
};

extern "C" void fn_27_FEE88(FeeSub *p, u32 v) {
    p->field = v;
}
