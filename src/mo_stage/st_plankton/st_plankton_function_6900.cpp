#pragma force_active on
typedef unsigned char u8;

extern "C" void* fn_74_6900(u8* self, int index) {
    int i = (*(int*)(self + 8) >> 30) + index;
    if (i >= 1) {
        i = i - 1;
    }
    return self + i * 0xA0 + 0xC;
}
