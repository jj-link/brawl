#pragma force_active on
typedef unsigned int u32;

struct FooBits {
    u32 pad0 : 6;
    u32 field : 3;
    u32 pad1 : 23;
};

struct FooObj {
    u32 unk0;
    u32 unk4;
    FooBits word8;
};

extern "C" {
void fn_27_3902BC(FooObj *p, u32 v)
{
    p->word8.field = v;
}
}
