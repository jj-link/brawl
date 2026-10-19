#pragma force_active on
extern "C" void* fn_48_B61C(void* base, int index) {
    int shift = *(int*)((char*)base + 8) >> 23;
    int sum = shift + index;
    if (sum >= 205)
        sum -= 205;
    return (char*)base + sum * 120 + 12;
}
