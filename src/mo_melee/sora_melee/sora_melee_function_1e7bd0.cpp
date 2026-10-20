#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 flags;
};

extern "C" {
s32 fn_27_1E7BD0(Obj* p)
{
    u32 f = (p->flags >> 27) & 7;
    return (s32)(f << 29) >> 30;
}
}
