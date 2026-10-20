#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad[2];
    u32 hi : 10;
    u32 lo : 22;
} S;

extern "C" {
void fn_27_1A3EA0(S* p, u32 v) {
    p->hi = v;
}
}
