#pragma force_active on
struct Fn113Obj {
    char pad[8];
    char *base;
    int count;
};

extern "C" void *fn_113_24AB8(Fn113Obj *self)
{
    return self->base + self->count * 12 + 4;
}
