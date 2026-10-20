#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad[2];
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
} Bits;

extern "C" {
void fn_27_FE944(Bits *p, u32 v)
{
    p->b = v;
}
}
