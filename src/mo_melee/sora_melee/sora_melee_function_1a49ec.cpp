#pragma force_active on
typedef unsigned int u32;

typedef struct Obj {
    u32 pad0;
    u32 pad4;
    u32 hi : 4;
    u32 mid : 4;
    u32 lo : 24;
} Obj;

extern "C" void fn_27_1A49EC(Obj *obj, u32 v)
{
    obj->mid = v;
}
