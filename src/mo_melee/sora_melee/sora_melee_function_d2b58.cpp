#pragma force_active on
typedef unsigned int u32;

struct FooObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_D2B58(FooObj *obj)
{
    obj->flags |= 0x80000;
}
