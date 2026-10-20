#pragma force_active on
extern "C" int* fn_27_F3EA4(void* p, int index)
{
    int value = *reinterpret_cast<int*>(static_cast<char*>(p) + 0x18);
    int adjusted = (value >> 30) + index;
    if (adjusted < 1)
        goto done;
    adjusted -= 1;
done:
    return reinterpret_cast<int*>(static_cast<char*>(p) + 0x1C + adjusted * 0xC);
}
