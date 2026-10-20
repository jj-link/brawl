#pragma force_active on
typedef unsigned int u32;

struct fn_27_AAA78_obj {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_AAA78(fn_27_AAA78_obj* obj)
{
    obj->flags &= ~0x00010000u;
}
