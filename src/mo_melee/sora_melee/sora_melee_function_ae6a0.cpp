#pragma force_active on
extern "C" void *fn_27_AE6A0(void *base, int index)
{
    int offset = *reinterpret_cast<int *>(static_cast<char *>(base) + 8) >> 30;
    int adjusted = offset + index;
    if (adjusted >= 1)
        adjusted -= 1;
    return static_cast<char *>(base) + adjusted * 12 + 12;
}
