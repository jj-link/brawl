#pragma force_active on
extern "C" unsigned char fn_27_111FDC(unsigned int* p) {
    unsigned char* q = (unsigned char*)p[0];
    unsigned char result = 0;
    if (q[0x70] == 0)
        result = 1;
    if (q[0x71] == 0)
        result = (unsigned char)(result + 1);
    if (q[0x72] == 0)
        result = (unsigned char)(result + 1);
    return result;
}
