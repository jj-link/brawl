#pragma force_active on
extern "C" void *fn_27_D9598(void *object, int index)
{
    int value = *reinterpret_cast<int *>(reinterpret_cast<char *>(object) + 8);
    int adjusted = (value >> 26) + index;

    if (adjusted >= 0x13)
        adjusted -= 0x13;

    return reinterpret_cast<char *>(object) + adjusted * 0x30 + 0x0C;
}
