#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8_hi : 14;
    u32 field : 7;
    u32 unk8_lo : 11;
} S;

extern "C" void fn_27_D0888(S* s, u32 v)
{
    s->field = v;
}
