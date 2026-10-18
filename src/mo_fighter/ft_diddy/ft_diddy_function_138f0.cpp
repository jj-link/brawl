#pragma force_active on
struct Inner
{
    char pad[0x20];
    void *field20;
};

struct Outer
{
    char pad[0xd8];
    struct Inner *fieldD8;
};

extern "C" void *fn_115_138F0(struct Outer *self)
{
    return self->fieldD8->field20;
}
