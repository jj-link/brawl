#pragma force_active on
struct Owner {
    unsigned char pad[0x28];
    unsigned char *base;
};

extern "C" {
void *fn_8004D138(Owner *self, int index)
{
    return self->base + index * 0x124;
}
}
