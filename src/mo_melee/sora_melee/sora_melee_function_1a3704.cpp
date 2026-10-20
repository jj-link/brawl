#pragma force_active on
typedef unsigned int u32;

struct BF {
    u32 a : 20;
    u32 b : 10;
    u32 c : 2;
};

extern "C" {
void fn_27_1A3704(void* p, u32 x)
{
    BF* s = (BF*)((char*)p + 8);
    s->b = x;
}
}
