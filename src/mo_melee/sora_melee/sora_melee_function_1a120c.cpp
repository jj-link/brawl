#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 hi : 10;
    u32 val : 5;
    u32 lo : 17;
};

extern "C" void fn_27_1A120C(S* s, u32 v) {
    s->val = v;
}
