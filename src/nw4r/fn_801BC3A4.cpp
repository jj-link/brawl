#pragma force_active on

extern "C" {
extern const float lbl_805A34A0;
extern const float lbl_805A34A4;
}

extern "C" void fn_801BC3A4(void* arg0) {
    char* p = (char*)arg0;
    float zero = lbl_805A34A4;
    float one = lbl_805A34A0;
    *(float*)(p + 0x10) = zero;
    *(float*)(p + 0x8) = one;
    *(float*)(p + 0xC) = one;
    *(float*)(p + 0x14) = zero;
    *(float*)(p + 0x18) = zero;
    *(unsigned char*)(p + 0x68) = 0;
    *(unsigned int*)(p + 0x6C) = 0;
    *(unsigned int*)(p + 0x70) = 0;
    *(int*)(p + 0x20) = 1;
    *(float*)(p + 0x28) = zero;
    *(float*)(p + 0x24) = one;
    *(float*)(p + 0x2C) = zero;
    *(float*)(p + 0x30) = zero;
    *(float*)(p + 0x34) = zero;
    *(float*)(p + 0x38) = one;
    *(float*)(p + 0x48) = zero;
    *(float*)(p + 0x58) = zero;
    *(float*)(p + 0x3C) = one;
    *(float*)(p + 0x4C) = zero;
    *(float*)(p + 0x5C) = zero;
    *(float*)(p + 0x40) = one;
    *(float*)(p + 0x50) = zero;
    *(float*)(p + 0x60) = zero;
    *(float*)(p + 0x44) = one;
    *(float*)(p + 0x54) = zero;
    *(float*)(p + 0x64) = zero;
}
