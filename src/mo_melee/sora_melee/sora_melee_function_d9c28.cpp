#pragma force_active on
extern "C" int* fn_27_D9C28(int* self, int index)
{
    int adjusted = (self[2] >> 29) + index;
    if (adjusted >= 3)
        adjusted -= 3;
    return reinterpret_cast<int*>(reinterpret_cast<char*>(self) + adjusted * 0x2C + 0xC);
}
