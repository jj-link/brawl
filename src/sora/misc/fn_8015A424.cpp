#pragma force_active on
struct Elem {
    char data[0xc];
};

struct Owner {
    char pad[0x14];
    struct Elem *list;
};

extern "C" {
struct Elem *fn_8015A424(struct Owner *self, int index)
{
    return self->list + index;
}
}
