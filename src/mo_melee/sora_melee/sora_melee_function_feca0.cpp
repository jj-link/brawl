#pragma force_active on
extern "C" unsigned int fn_27_FECA0(const void* ptr) {
    unsigned int val = *(const unsigned int*)((const unsigned char*)ptr + 8);
    return (val >> 10) & 1;
}
