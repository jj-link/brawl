#pragma force_active on
typedef unsigned int u32;

struct FooObj {
    char pad[8];
    u32 hi : 4;
    u32 f : 2;
    u32 lo : 26;
};

extern "C" {
void fn_27_D3178(FooObj *obj, u32 val)
{
    obj->f = val;
}
}
