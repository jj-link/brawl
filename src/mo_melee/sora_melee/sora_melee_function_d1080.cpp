#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Bf {
    u32 pad[2];
    u32 a : 16;
    u32 b : 8;
    u32 c : 8;
};

extern "C" {
void fn_27_D1080(Bf *p, u8 v)
{
    p->b = v;
}
}
