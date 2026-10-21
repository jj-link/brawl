#pragma force_active on
typedef unsigned int u32;

struct Fn80111Obj {
    char pad[0x14];
    u32 field14;
};

extern "C" {
u32 fn_80111C54(Fn80111Obj *p, u32 x)
{
    return (x - p->field14) / 18;
}
}
