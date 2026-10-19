#pragma force_active on
extern "C" void* fn_49_7028(unsigned char* base, int index) {
    int header = *(int*)(base + 8);
    int sum = (header >> 28) + index;
    if (sum >= 6) {
        sum -= 6;
    }
    return base + sum * 8 + 12;
}
