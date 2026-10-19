#pragma force_active on
extern "C" unsigned int fn_6_A09C(unsigned char* self) {
    unsigned char* p = *(unsigned char**)(self + 0x730);
    if (p[0x8c] == 0) {
        return *(unsigned int*)(self + 0x124);
    }
    if (*(unsigned int*)(p + 0x90) == 0) {
        return 12;
    }
    *(unsigned int*)(self + 0x778) = 9;
    return 2;
}
