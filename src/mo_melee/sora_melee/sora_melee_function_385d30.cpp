#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
} FnObj27;

extern "C" void fn_27_385D30(FnObj27* p, u32 v)
{
    p->b = v;
}
