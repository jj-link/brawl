#pragma force_active on
extern "C" int* fn_27_D9C50(int* base, int index)
{
    int adjusted = (base[2] >> 30) + index;
    if (adjusted >= 1)
        adjusted -= 1;

    return (int*)((char*)base + adjusted * 0x2C + 0x0C);
}
