#pragma force_active on
struct Obj {
    unsigned char pad[0x18];
    int flags;
    unsigned char data[1];
};

extern "C" void *fn_27_2645E8(Obj *self, int index)
{
    int adjusted = (self->flags >> 30) + index;
    if (adjusted >= 1)
        adjusted--;
    return self->data + adjusted * 12;
}
