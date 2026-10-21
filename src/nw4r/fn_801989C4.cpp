#pragma force_active on
extern "C" unsigned int fn_801989C4(void* obj, int index)
{
    unsigned short* arr = *(unsigned short**)((char*)obj + 0x14);
    return (arr[index] & 0xC000) == 0;
}
