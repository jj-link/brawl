#pragma force_active on
extern "C" void* fn_27_D9BD8(void* p1, int p2)
{
    int index = (*(int*)((char*)p1 + 8) >> 29) + p2;
    if (index >= 2)
        index -= 2;
    return (char*)p1 + index * 0x1C + 0x0C;
}
