#pragma force_active on
extern "C" void* fn_27_1B1274(void* object, int index)
{
    int high = *reinterpret_cast<int*>(
        static_cast<char*>(object) + 8) >> 28;

    int adjusted = high + index;
    if (adjusted >= 4)
        adjusted = adjusted - 4;

    return static_cast<char*>(object) + adjusted * 0x90 + 0x0C;
}
