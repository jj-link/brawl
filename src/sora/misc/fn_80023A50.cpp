#pragma force_active on
extern "C" void* lbl_8059FFFC;
extern "C" void fn_80023A50(void* p) {
    unsigned char* b = (unsigned char*)p;
    unsigned int* w = (unsigned int*)p;
    unsigned char flags = b[0x74];
    b[5] = 0xF0;
    b[6] = 0xF1;
    b[7] = 0xF0;
    b[8] = 0;
    w[8] = 0;
    w[9] = 0;
    w[10] = 0;
    w[21] = 0;
    w[20] = 0;
    w[19] = 0;
    w[18] = 0;
    w[17] = 0;
    w[16] = 0;
    w[27] = 0;
    w[26] = 0;
    w[25] = 0;
    w[24] = 0;
    w[23] = 0;
    w[22] = 0;
    w[28] = 0;
    b[0x74] = ((flags | 0xC0) & ~0x30) | 8;
    lbl_8059FFFC = p;
}