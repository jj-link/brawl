#pragma force_active on
extern "C" void* fn_27_1CA2E0(void* self, int idx) {
    int base = *(int*)((char*)self + 0x18) >> 28;
    int sum = base + idx;
    if (sum >= 4) {
        sum -= 4;
    }
    return (char*)self + sum * 12 + 0x1c;
}
