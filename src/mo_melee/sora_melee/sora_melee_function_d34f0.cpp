#pragma force_active on
typedef unsigned int u32;

typedef struct {
    char pad[8];
    u32 flags;
} FlagObj;

extern "C" void fn_27_D34F0(FlagObj *obj)
{
    obj->flags |= 0x400000;
}
