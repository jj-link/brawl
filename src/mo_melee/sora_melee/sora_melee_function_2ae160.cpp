#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
    u32 pad : 4;
    u32 f : 2;
    u32 rest : 26;
} S;

extern "C" {
void fn_27_2AE160(S *p, u32 v) {
    p->f = v;
}
}
