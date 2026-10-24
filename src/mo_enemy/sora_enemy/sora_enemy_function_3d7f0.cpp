#pragma force_active on
#pragma section data_type ".data" ".bss"

extern "C" int fn_41_3D7F0(void*, int n) {
    unsigned char buf[0x22];
    unsigned char* p = buf;
    switch(n) {
    case 0: p[0x20] = 0; p[0x21] = 0; return 3;
    case 1: p[0x1E] = 0; p[0x1F] = 0; return 0;
    case 2: p[0x1C] = 0; p[0x1D] = 0; return 0;
    case 3: p[0x1A] = 0; p[0x1B] = 0; return 0;
    case 4: p[0x18] = 0; p[0x19] = 0; return 0;
    case 5: p[0x16] = 0; p[0x17] = 0; return 0;
    case 6: p[0x14] = 0; p[0x15] = 0; return 0;
    case 7: p[0x12] = 0; p[0x13] = 0; return 0;
    case 8: p[0x10] = 0; p[0x11] = 0; return 0;
    case 9: p[0xE] = 0; p[0xF] = 0; return 0;
    case 10: p[0xC] = 0; p[0xD] = 0; return 0;
    case 11: p[0xA] = 0; p[0xB] = 0; return 0;
    case 12: p[8] = 0; p[9] = 0; return 0;
    case 13: p[6] = 0; p[7] = 0; return 0;
    case 14: p[4] = 0; p[5] = 0; return 0;
    case 15: p[2] = 0; p[3] = 0; return 0;
    case 16: p[0] = 0; p[1] = 0; return 0;
    default: return 0;
    }
}