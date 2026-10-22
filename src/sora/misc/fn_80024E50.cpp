#pragma force_active on
extern "C" {
extern unsigned char lbl_80494E00[];
extern unsigned char lbl_80494EE8[];
extern int lbl_805A0010;
extern int lbl_805A0014;
extern float lbl_805A0018;
extern float lbl_805A1500;
extern float lbl_805A1504;

void fn_80024E50(void) {
    unsigned char* p;
    int i;
    int z;
    float f = lbl_805A1500;
    z = 0;
    p = lbl_80494EE8;
    for (i = 0; i < 7; i++) {
        *(int*)(p + 0x8) = z;
        *(int*)(p + 0xC) = z;
        *(int*)(p + 0x10) = z;
        *(int*)(p + 0x14) = z;
        *(int*)(p + 0x18) = z;
        *(int*)(p + 0x1C) = z;
        *(int*)(p + 0x20) = z;
        *(int*)(p + 0x24) = z;
        *(int*)(p + 0x28) = z;
        *(int*)(p + 0x2C) = z;
        *(int*)(p + 0x30) = z;
        *(int*)(p + 0x34) = z;
        *(int*)(p + 0x38) = z;
        *(int*)(p + 0x3C) = z;
        *(int*)(p + 0x40) = z;
        *(int*)(p + 0x44) = z;
        *(unsigned char*)(p + 0x0) = z;
        *(int*)(p + 0x48) = z;
        *(int*)(p + 0x4C) = z;
        *(float*)(p + 0x50) = f;
        *(float*)(p + 0x54) = f;
        *(float*)(p + 0x58) = f;
        *(float*)(p + 0x5C) = f;
        *(float*)(p + 0x60) = f;
        *(float*)(p + 0x64) = f;
        p += 0x68;
    }
    lbl_805A0010 = 0x40;
    lbl_805A0014 = 0x40;
    lbl_805A0018 = lbl_805A1504;
    lbl_80494E00[0] = 0;
}
}
