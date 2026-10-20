#pragma force_active on
typedef unsigned int u32;

struct FooObj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 2;
        u32 b : 2;
        u32 c : 28;
    } flags;
};

extern "C" void fn_27_D3114(FooObj *obj, u32 val)
{
    obj->flags.b = val;
}
