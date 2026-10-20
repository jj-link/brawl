#pragma force_active on
typedef unsigned int u32;

struct S {
    char pad[8];
    u32 a : 6;
    u32 f : 3;
    u32 b : 23;
};

extern "C" {
void fn_27_1A5478(S* s, u32 v) {
    s->f = v;
}
}
