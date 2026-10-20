#pragma force_active on
typedef unsigned int u32;

typedef struct Obj {
    char pad[8];
    u32 flags;
} Obj;

extern "C" void fn_27_FEA58(Obj* obj)
{
    obj->flags |= 0x00400000;
}
