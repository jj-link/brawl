#pragma force_active on
extern "C" void* fn_27_FEF94(void* object, int index)
{
    int offset = *(int*)((char*)object + 8) >> 30;
    int adjusted = offset + index;
    if (adjusted >= 1)
        adjusted -= 1;
    return (char*)object + adjusted * 12 + 12;
}
