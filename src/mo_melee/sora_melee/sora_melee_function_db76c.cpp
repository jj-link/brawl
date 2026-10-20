#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 pad[2];
    u32 p : 4;
    s32 x : 2;
    u32 q : 26;
};

extern "C" s32 fn_27_DB76C(Obj *o)
{
    return o->x;
}
