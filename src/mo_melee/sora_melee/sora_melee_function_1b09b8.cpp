#pragma force_active on
extern "C" void* fn_27_1B09B8(void* p, int index)
{
    int offset = *(int*)((char*)p + 8) >> 29;
    int adjusted = offset + index;
    if (adjusted >= 2)
        adjusted -= 2;
    return (char*)p + adjusted * 0x90 + 0xC;
}
