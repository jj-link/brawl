#pragma force_active on
extern "C" void *fn_27_FE864(void *self, int offset)
{
    int shift = *reinterpret_cast<int *>(static_cast<char *>(self) + 8) >> 30;
    int index = shift + offset;
    if (index >= 1)
        index -= 1;
    return static_cast<char *>(self) + 12 + index * 12;
}
