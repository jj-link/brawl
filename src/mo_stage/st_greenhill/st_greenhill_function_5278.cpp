#pragma force_active on
extern "C" void* fn_72_5278(char* obj, int index) {
    int field = *(int*)(obj + 8);
    int sum = (field >> 30) + index;
    int n = sum >= 1 ? sum - 1 : sum;
    return obj + n * 0x90 + 0xc;
}
