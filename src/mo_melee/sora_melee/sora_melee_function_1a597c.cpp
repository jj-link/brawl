#pragma force_active on
extern "C" int fn_27_1A597C(const unsigned int* p)
{
    return (int)((*(const unsigned int*)((const char*)p + 8) & 0x00FF0000) << 10) >> 27;
}
