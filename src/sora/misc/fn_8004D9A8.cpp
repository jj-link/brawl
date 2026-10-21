#pragma force_active on
extern "C" int fn_8004D9A8(unsigned char* p, int i) {
    unsigned char* q = *(unsigned char**)(p + 0x28) + i * 0x124;
    if (*(unsigned short*)(q + 0xe0) == 0) {
        return 0;
    }
    return (q[0xec] - 1) == 0;
}
