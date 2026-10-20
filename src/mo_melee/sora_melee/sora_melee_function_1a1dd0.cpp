#pragma force_active on
extern "C" unsigned int fn_27_1A1DD0(const void* self) {
    unsigned int val = *(const unsigned int*)((const char*)self + 8);
    return (val >> 13) & 1;
}
