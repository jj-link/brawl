#pragma force_active on
struct Entry {
    char data[0xc];
};

struct Owner {
    char pad[0x18];
    Entry* entries;
};

extern "C" {
Entry* fn_8015A7CC(Owner* self, int idx)
{
    return self->entries + idx;
}
}
