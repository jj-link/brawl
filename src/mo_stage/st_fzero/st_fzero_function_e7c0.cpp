#pragma force_active on
struct Flags {
    unsigned int a : 6;
    unsigned int f : 3;
    unsigned int b : 23;
};

struct Obj {
    char pad[8];
    struct Flags flags;
};

extern "C" void fn_61_E7C0(struct Obj *self, unsigned int v)
{
    self->flags.f = v;
}
