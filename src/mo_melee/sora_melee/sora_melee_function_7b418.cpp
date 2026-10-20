#pragma force_active on
extern "C" void fn_27_7B418(unsigned int* self, int index, unsigned int value)
{
    if (index <= -1 || index >= 1)
        return;

    unsigned int mask = 1u << index;
    self[0] |= mask;

    if (value == 1)
        self[1] |= mask;
    else
        self[1] &= ~mask;
}
