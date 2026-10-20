#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad[2];
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
} Bits;

extern "C" {
void fn_27_CB0DC(Bits *p, u32 v)
{
    p->b = v;
}
}
