#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 w0;
    u32 w1;
    u32 field : 6;
    u32 rest : 26;
};

extern "C" void fn_27_1CF83C(S* p, u32 v) {
    p->field = v;
}
