#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A33C4_obj {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_1A33C4(fn_27_1A33C4_obj* self)
{
    self->flags &= ~2u;
}
