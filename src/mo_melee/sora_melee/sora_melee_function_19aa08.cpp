#pragma force_active on
typedef unsigned int u32;

struct fn_27_19AA08_Obj {
    char pad[8];
    u32 flags;
};

extern "C" {
void fn_27_19AA08(fn_27_19AA08_Obj* obj)
{
    obj->flags |= 0x400000;
}
}
