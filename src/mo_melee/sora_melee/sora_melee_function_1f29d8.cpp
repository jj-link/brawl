#pragma force_active on
struct Data {
    unsigned char padding[0x32C];
    unsigned char flags[24];
};

extern "C" void fn_27_1F29D8(Data* self, int index, unsigned int mask)
{
    if (index < 0 || (unsigned int)index >= 24 || self->flags[index] == 0)
        return;

    self->flags[index] |= mask;
}
