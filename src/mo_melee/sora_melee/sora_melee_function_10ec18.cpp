#pragma force_active on
extern "C" unsigned int fn_27_10EC18(const void* ptr) {
    unsigned int val = *(const unsigned int*)((const char*)ptr + 8);
    return (val >> 16) & 1u;
}
