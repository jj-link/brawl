#pragma force_active on
extern "C" int fn_27_1A51FC(const unsigned int* p)
{
    unsigned int value = *(const unsigned int*)((const char*)p + 8);
    value = (value >> 25) & 0x0F;
    return (int)(value << 28) >> 29;
}
