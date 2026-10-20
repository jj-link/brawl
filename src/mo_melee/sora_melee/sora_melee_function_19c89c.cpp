#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FooObj {
    char pad[8];
    u32 flags;
};

extern "C" {
s32 fn_27_19C89C(FooObj* p)
{
    return (s32)(((p->flags >> 27) & 7) << 29) >> 30;
}
}
