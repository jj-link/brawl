#pragma force_active on
typedef unsigned int u32;

typedef struct Obj
{
    u32 pad[2];
    u32 hi : 3;
    u32 lo : 29;
} Obj;

extern "C" void fn_73_AB40(Obj *o, u32 v)
{
    o->hi = v;
}
