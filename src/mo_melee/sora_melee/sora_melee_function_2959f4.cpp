#pragma force_active on
extern "C" void* fn_27_2959F4(void* obj, int idx) {
    int bits = (int)((unsigned int*)obj)[2] >> 28;
    int sum = bits + idx;
    if (sum >= 7) {
        sum -= 7;
    }
    return (char*)obj + sum * 4 + 12;
}
