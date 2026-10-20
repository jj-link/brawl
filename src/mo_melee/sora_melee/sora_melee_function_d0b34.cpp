#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 hi : 7;
    u32 lo : 25;
};

extern "C" {
void fn_27_D0B34(Obj *obj, u32 v)
{
    obj->hi = v;
}
}
