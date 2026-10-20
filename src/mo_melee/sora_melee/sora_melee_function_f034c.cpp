#pragma force_active on
struct Object {
    char pad[0x18];
    int flags;
    char entries[1];
};

extern "C" void *fn_27_F034C(Object *self, int index)
{
    int sum = (self->flags >> 30) + index;
    if (sum >= 1)
        sum -= 1;
    return (char *)self + 0x1C + sum * 0x0C;
}
