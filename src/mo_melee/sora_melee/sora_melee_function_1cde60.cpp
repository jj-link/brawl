#pragma force_active on
extern "C" int* fn_27_1CDE60(void* object, int index)
{
    int shift = *reinterpret_cast<int*>(static_cast<char*>(object) + 0x18) >> 28;
    int adjusted = shift + index;

    if (adjusted < 4)
        adjusted = adjusted;

    if (adjusted >= 4)
        adjusted -= 4;

    return reinterpret_cast<int*>(static_cast<char*>(object) + 0x1C + adjusted * 12);
}
