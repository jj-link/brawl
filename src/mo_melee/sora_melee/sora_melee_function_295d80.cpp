#pragma force_active on
typedef unsigned int u32;

struct fn_27_295D80_obj {
    u32 unk0;
    u32 unk4;
    u32 flag : 4;
    u32 rest : 28;
};

extern "C" {
void fn_27_295D80(fn_27_295D80_obj* p, u32 v)
{
    p->flag = v;
}
}
