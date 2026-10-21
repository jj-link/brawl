#pragma force_active on
extern "C" void* fn_8032E9B4(void* self, int idx);

struct Elem {
    char data[0x30];
};

struct Owner {
    char pad0[0x10];
    Elem *list;
    char pad1[0x8];
    unsigned char *flags;
};

extern "C" void* fn_8032D978(Owner *self, int idx)
{
    if (self->flags[idx] & 2) {
        return fn_8032E9B4(self, idx);
    }
    return self->list + idx;
}
