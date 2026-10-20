#pragma force_active on
extern "C" int fn_27_ABFCC(const unsigned int* p)
{
    unsigned int x = *(const unsigned int*)((const char*)p + 8);
    x = (x << 12) & 0xFE000000;
    return (int)x >> 26;
}
