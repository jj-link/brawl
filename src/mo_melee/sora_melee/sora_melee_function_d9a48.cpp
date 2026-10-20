#pragma force_active on
extern "C" int* fn_27_D9A48(int* p, int index)
{
    int n = (p[2] >> 27) + index;
    if (n >= 8)
        n -= 8;
    return (int*)((char*)p + n * 0x24 + 0xC);
}
