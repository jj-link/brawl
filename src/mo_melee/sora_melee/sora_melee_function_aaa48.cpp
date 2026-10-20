#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
    u32 hi : 5;
    u32 f : 5;
    u32 lo : 22;
} fn_27_AAA48_S;

extern "C" void fn_27_AAA48(fn_27_AAA48_S* p, u32 v) {
    p->f = v;
}
