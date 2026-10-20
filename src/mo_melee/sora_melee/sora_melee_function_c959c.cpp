#pragma force_active on
typedef unsigned int u32;

struct FooObj {
    u32 unk0;
    u32 unk4;
    u32 flag : 3;
    u32 rest : 29;
};

extern "C" void fn_27_C959C(FooObj *p, u32 v)
{
    p->flag = v;
}
