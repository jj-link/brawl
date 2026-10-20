#pragma force_active on
typedef unsigned int u32;

typedef struct Obj
{
    u32 pad0;
    u32 pad1;
    u32 flags;
} Obj;

extern "C" {
void fn_62_61D8(Obj *obj)
{
    obj->flags &= ~0x00080000;
}
}
