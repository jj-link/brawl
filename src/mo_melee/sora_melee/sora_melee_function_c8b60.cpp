#pragma force_active on
extern "C" int fn_27_C8B60(const void *object)
{
    const int value = *(const int *)((const char *)object + 4);
    return (value >> 27) < 0;
}
