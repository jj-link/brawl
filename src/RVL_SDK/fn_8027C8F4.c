#pragma force_active on
struct Owner {
    char pad[0x18];
    char *base;
};

void *fn_8027C8F4(struct Owner *self, int index)
{
    return self->base + index * 0x14;
}
