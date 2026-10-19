#pragma force_active on
extern "C" void* fn_79_588C(char* base, int index) {
    int sum = (*(int*)(base + 8) >> 26) + index;
    if (sum < 30) {
    } else {
        sum -= 30;
    }
    return base + sum * 56 + 12;
}
