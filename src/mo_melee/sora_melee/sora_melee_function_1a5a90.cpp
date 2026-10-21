#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 low : 20;
    u32 field : 10;
    u32 top : 2;
};

extern "C" void fn_27_1A5A90(Obj* p, u32 v)
{
    p->field = v;
}
