#pragma force_active on
struct Elem {
    char data[0x60];
};

struct Owner {
    char pad[0x34];
    struct Elem *list;
};

extern "C" struct Elem *fn_801C96A8(struct Owner *self, int index)
{
    return self->list + index;
}
