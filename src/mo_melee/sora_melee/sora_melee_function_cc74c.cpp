#pragma force_active on
typedef unsigned int u32;

struct BitfieldWord {
    u32 a;
    u32 b;
    u32 hi : 6;
    u32 val : 3;
    u32 lo : 23;
};

extern "C" {
void fn_27_CC74C(BitfieldWord* p, u32 v)
{
    p->val = v;
}
}
