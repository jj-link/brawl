#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flag : 7;
    u32 rest : 25;
} fn_27_D033C_obj;

extern "C" {
void fn_27_D033C(void *p, u32 v)
{
    fn_27_D033C_obj *o = (fn_27_D033C_obj *)p;
    o->flag = v;
}
}
