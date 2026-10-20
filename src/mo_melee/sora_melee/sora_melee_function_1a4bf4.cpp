#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 hi : 4;
    u32 field : 4;
    u32 lo : 24;
} S;

extern "C" void fn_27_1A4BF4(S* p, u32 v)
{
    p->field = v;
}
