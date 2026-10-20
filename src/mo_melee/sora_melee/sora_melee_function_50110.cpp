#pragma force_active on
typedef unsigned int u32;

struct Fn27Obj {
    char pad[0x94];
    u32 field94;
};

extern "C" {
unsigned int fn_27_50110(Fn27Obj *p, u32 x)
{
    return (x - p->field94) / 44;
}
}
