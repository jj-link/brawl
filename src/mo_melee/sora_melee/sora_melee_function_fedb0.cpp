#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 hi : 6;
    u32 rest : 26;
} fn_27_FEDB0_Obj;

extern "C" {
void fn_27_FEDB0(fn_27_FEDB0_Obj* p, u32 v)
{
    p->hi = v;
}
}
