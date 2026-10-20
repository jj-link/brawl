#pragma force_active on
struct Elem {
    char data[0x18];
};

struct Owner {
    char pad[0x154];
    struct Elem *list;
};

extern "C" struct Elem *fn_40_2E3CC(struct Owner *self, int index)
{
    return self->list + index;
}
