#pragma force_active on
extern "C" int fn_110_9848(const void* work, unsigned int mask, unsigned int index) {
    const unsigned int* arr = (const unsigned int*)*((const unsigned int*)work + 7);
    return (arr[index] & mask) ? 1 : 0;
}
