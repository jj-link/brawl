#pragma force_active on
extern "C" void* fn_27_1B0AF8(void* p, int index)
{
    int adjusted = (*(int*)((char*)p + 8) >> 30) + index;
    if (adjusted >= 1)
        adjusted -= 1;
    return (char*)p + adjusted * 12 + 12;
}
