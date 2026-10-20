#pragma force_active on
typedef unsigned int u32;

typedef struct Obj
{
    u32 pad[2];
    u32 flags;
} Obj;

extern "C" {
int fn_57_AE3C(Obj *o)
{
    u32 v = o->flags;
    return (int)(((v << 4) | (v >> 28)) & 0xF8000000u) >> 28;
}
}
