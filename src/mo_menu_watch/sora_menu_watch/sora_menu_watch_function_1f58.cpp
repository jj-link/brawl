#pragma force_active on
extern "C" int fn_15_1F58(void* a, void* b)
{
    unsigned int value_b = *(unsigned int*)((char*)b + 0x0C);
    unsigned int value_a = *(unsigned int*)((char*)a + 0x0C);
    return value_a - value_b;
}
