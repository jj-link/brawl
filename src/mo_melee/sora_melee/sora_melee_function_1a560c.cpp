#pragma force_active on
extern "C" int fn_27_1A560C(const void* p) {
    unsigned int v = *(const unsigned int*)((const char*)p + 8);
    return (int)((int)(v << 4) & 0xF8000000) >> 28;
}
