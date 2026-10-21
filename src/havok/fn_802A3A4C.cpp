#pragma force_active on
extern "C" {

extern float lbl_805A3ED8;
extern const unsigned char lbl_80486834[];

void fn_802A3A4C(char* p, int arg1) {
    float x = lbl_805A3ED8;
    *(unsigned short*)(p + 6) = 1;
    *(int*)(p + 8) = arg1;
    *(const unsigned char**)(p + 0x00) = lbl_80486834;
    *(int*)(p + 0x0C) = 0;
    *(int*)(p + 0x10) = 0;
    *(unsigned int*)(p + 0x14) = 0x80000000;
    *(float*)(p + 0x30) = x;
    *(float*)(p + 0x34) = x;
    *(float*)(p + 0x38) = x;
    *(float*)(p + 0x3C) = x;
    *(float*)(p + 0x20) = x;
    *(float*)(p + 0x24) = x;
    *(float*)(p + 0x28) = x;
    *(float*)(p + 0x2C) = x;
}

}
