#pragma force_active on
extern "C" int fn_72_1A78(const void *self) {
    int v = *(const unsigned char *)((const char *)self + 0x6c);
    return (v >> 3) & 1;
}
