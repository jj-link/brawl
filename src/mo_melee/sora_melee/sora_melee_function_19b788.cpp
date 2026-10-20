#pragma force_active on
extern "C" int fn_27_19B788(const unsigned int* p) {
    unsigned int value = *(const unsigned int*)((const char*)p + 8);
    return (int)((value << 6) & 0xFE000000u) >> 26;
}
