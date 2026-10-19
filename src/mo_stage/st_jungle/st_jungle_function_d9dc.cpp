#pragma force_active on
extern "C" void* fn_51_D9DC(unsigned char* self, int index) {
    int shift = *(int*)(self + 8) >> 29;
    int sum = shift + index;
    if (sum >= 2) {
        sum -= 2;
    }
    return self + sum * 0x78 + 0xC;
}
