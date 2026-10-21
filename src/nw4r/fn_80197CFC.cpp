#pragma force_active on
extern "C" int fn_80197CFC(void* obj, int index)
{
    const unsigned short* arr = *(const unsigned short**)((char*)obj + 0x14);
    return (arr[index] & 0xC000) == 0;
}
