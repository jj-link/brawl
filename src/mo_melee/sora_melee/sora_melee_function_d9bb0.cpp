#pragma force_active on
extern "C" void *fn_27_D9BB0(void *object, int index)
{
    int flags = *reinterpret_cast<int *>(static_cast<char *>(object) + 8);
    int adjusted = (flags >> 30) + index;
    if (adjusted >= 1)
        --adjusted;
    return static_cast<char *>(object) + adjusted * 0x48 + 0x0C;
}
