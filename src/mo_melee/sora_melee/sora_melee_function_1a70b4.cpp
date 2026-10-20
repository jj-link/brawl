#pragma force_active on
extern "C" {
unsigned fn_27_1A70B4(const void* p) {
    unsigned val = *(const unsigned*)((const char*)p + 8);
    return (val >> 19) & 1;
}
}
