#pragma force_active on
typedef unsigned int u32;

struct BF {
    u32 w0;
    u32 w1;
    u32 hi : 10;
    u32 mid : 10;
    u32 lo : 12;
};

extern "C" {
void fn_27_1A6864(BF* p, u32 v)
{
    p->mid = v;
}
}
