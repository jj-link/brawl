#pragma force_active on
extern "C" int* fn_27_F9780(void* object, int index)
{
    int count = (*(int*)((char*)object + 0x18) >> 27) + index;
    if (count >= 12)
        count -= 12;
    return (int*)((char*)object + count * 12 + 0x1C);
}
