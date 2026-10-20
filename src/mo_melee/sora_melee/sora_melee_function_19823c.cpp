#pragma force_active on
typedef unsigned int u32;

struct S {
    char pad[8];
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" {
void fn_27_19823C(S* p, u32 v) {
    p->b = v;
}
}
