#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 f0 : 4;
    u32 f1 : 4;
    u32 f2 : 24;
};

extern "C" {
void fn_27_1D00FC(Obj *p, u32 v)
{
    p->f1 = v;
}
}
