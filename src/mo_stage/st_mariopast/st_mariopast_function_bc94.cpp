#pragma force_active on
extern "C" void* fn_48_BC94(unsigned char* self, int index) {
    int i = (*(int*)(self + 8) >> 26) + index;
    if (i >= 25) {
        i -= 25;
    }
    return self + 0xC + i * 0x68;
}
