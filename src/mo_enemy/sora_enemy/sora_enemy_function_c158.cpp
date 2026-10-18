#pragma force_active on
typedef unsigned int u32;

struct Fn41Holder {
    char pad[0x1c];
    u32 *bits;
};

extern "C" {
void fn_41_C158(Fn41Holder *self, u32 mask, u32 index)
{
    u32 *p = self->bits;
    p[index] &= ~mask;
}
}
