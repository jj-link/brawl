#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 a : 7;
    u32 f : 7;
    u32 b : 18;
} fn_27_CFE94_S;

extern "C" {
void fn_27_CFE94(fn_27_CFE94_S *p, u32 v)
{
    p->f = v;
}
}
