#pragma force_active on
struct Entry {};

extern "C" Entry* fn_27_1CD454(void* p, int index)
{
    int n = *(int*)((char*)p + 0x18) >> 28;
    int sum = n + index;
    if (sum >= 4)
        sum -= 4;
    return (Entry*)((char*)p + 0x1C + sum * 12);
}
