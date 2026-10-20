#pragma force_active on
typedef unsigned int u32;

typedef struct FnObj49
{
    u32 pad0;
    u32 pad4;
    u32 flags;
} FnObj49;

extern "C" void fn_49_6FE4(FnObj49 *obj)
{
    obj->flags |= 0x80000;
}
