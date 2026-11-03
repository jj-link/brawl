#pragma force_active on
extern "C" void fn_800B96E8(void* arg0, unsigned int arg1) {
    char* p = (char*)arg0;
    *(unsigned int*)(p + 0) = 1;
    if (arg1 != 0xFF) {
        if (arg1 == 0xF0) {
            *(unsigned char*)(p + 4) = 0xFF;
        } else {
            *(unsigned char*)(p + 4) = (1 << arg1);
        }
    } else {
        *(unsigned char*)(p + 4) = 0;
    }
    *(unsigned int*)(p + 0x2C) = 0;
    *(unsigned char*)(p + 0x30) = 0;
    *(unsigned char*)(p + 0x31) = 0;
    *(unsigned int*)(p + 0x4C) = 0;
    *(unsigned char*)(p + 0x50) = 0;
    *(unsigned char*)(p + 0x51) = 0;
    *(unsigned int*)(p + 0x6C) = 0;
    *(unsigned char*)(p + 0x70) = 0;
    *(unsigned char*)(p + 0x71) = 0;
    *(unsigned int*)(p + 0x34) = 0;
    *(unsigned char*)(p + 0x38) = 0;
    *(unsigned char*)(p + 0x39) = 0;
    *(unsigned int*)(p + 0x54) = 0;
    *(unsigned char*)(p + 0x58) = 0;
    *(unsigned char*)(p + 0x59) = 0;
    *(unsigned int*)(p + 0x74) = 0;
    *(unsigned char*)(p + 0x78) = 0;
    *(unsigned char*)(p + 0x79) = 0;
    *(unsigned int*)(p + 0x3C) = 0;
    *(unsigned char*)(p + 0x40) = 0;
    *(unsigned char*)(p + 0x41) = 0;
    *(unsigned int*)(p + 0x5C) = 0;
    *(unsigned char*)(p + 0x60) = 0;
    *(unsigned char*)(p + 0x61) = 0;
    *(unsigned int*)(p + 0x7C) = 0;
    *(unsigned char*)(p + 0x80) = 0;
    *(unsigned char*)(p + 0x81) = 0;
    *(unsigned int*)(p + 0x44) = 0;
    *(unsigned char*)(p + 0x48) = 0;
    *(unsigned char*)(p + 0x49) = 0;
    *(unsigned int*)(p + 0x64) = 0;
    *(unsigned char*)(p + 0x68) = 0;
    *(unsigned char*)(p + 0x69) = 0;
    *(unsigned int*)(p + 0x84) = 0;
    *(unsigned char*)(p + 0x88) = 0;
    *(unsigned char*)(p + 0x89) = 0;
    *(unsigned int*)(p + 0x98) = 0;
    *(unsigned char*)(p + 0x9C) = 0;
    *(unsigned char*)(p + 0x9D) = 0;
    *(unsigned int*)(p + 0x08) = 0;
    *(unsigned int*)(p + 0x0C) = 0;
    *(unsigned int*)(p + 0x10) = 0;
    *(unsigned int*)(p + 0x14) = 0;
    *(unsigned int*)(p + 0x18) = 0;
    *(unsigned int*)(p + 0x1C) = 0;
    *(unsigned int*)(p + 0x20) = 0;
    *(unsigned int*)(p + 0x24) = 0;
    *(unsigned int*)(p + 0x28) = 0;
    *(unsigned int*)(p + 0x8C) = 8;
    *(unsigned int*)(p + 0x90) = 8;
    *(unsigned int*)(p + 0x94) = 8;
    *(unsigned char*)(p + 0xA0) = 0;
    *(unsigned char*)(p + 0xA1) = 0;
    *(unsigned int*)(p + 0xA4) = 0;
}