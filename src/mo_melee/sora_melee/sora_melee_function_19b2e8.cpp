#pragma force_active on
typedef unsigned int u32;

struct fn_27_Obj {
    u32 unk0;
    u32 unk4;
    u32 field : 5;
};

extern "C" {
void fn_27_19B2E8(fn_27_Obj *p, u32 v)
{
    p->field = v;
}
}
