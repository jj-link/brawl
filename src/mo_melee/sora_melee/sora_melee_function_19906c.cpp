#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
} Bits;

typedef struct {
    u32 pad[2];
    Bits bits;
} Outer;

extern "C" {
void fn_27_19906C(Outer *p, u32 v)
{
    p->bits.b = v;
}
}
