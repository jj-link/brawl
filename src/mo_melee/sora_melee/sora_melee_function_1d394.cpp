#pragma force_active on
extern "C" int* fn_27_1D394(int* p, int offset)
{
    int index = (p[2] >> 26) + offset;
    if (index >= 20)
        index -= 20;
    return (int*)((char*)p + index * 12 + 12);
}
