#pragma force_active on

extern "C" double fn_8040036C(float x);
extern const double lbl_805A2D00;
extern const float lbl_805A2CE0;
extern const float lbl_805A2CE4;
extern const float lbl_805A2CE8;
extern const float lbl_805A2CEC;
extern const float lbl_805A2CF0;
extern const float lbl_805A2CF4;
extern const float lbl_805A2CF8;

#define BYTE_AT(p, o) (*(unsigned char*)((unsigned char*)(p) + (o)))
#define WORD_AT(p, o) (*(unsigned int*)((unsigned char*)(p) + (o)))
#define HALF_AT(p, o) (*(unsigned short*)((unsigned char*)(p) + (o)))
#define FLOAT_AT(p, o) (*(float*)((unsigned char*)(p) + (o)))
#define d ((unsigned char*)arg0)
#define s ((unsigned char*)arg1)

extern "C" void fn_8016B6E0(unsigned char* arg0, unsigned char* arg1, unsigned char* arg2) {
    unsigned char* pf;
    float f2;
    unsigned char* sub;
    unsigned int r;
    int i;
    unsigned char byte;

    BYTE_AT(d, 0x0) = BYTE_AT(s, 0x0);
    byte = BYTE_AT(s, 0x1);
    i = 0;
    BYTE_AT(d, 0x1) = byte;
    BYTE_AT(d, 0x2) = BYTE_AT(s, 0x2);
    BYTE_AT(d, 0x3) = BYTE_AT(s, 0x3);
    BYTE_AT(d, 0x4) = BYTE_AT(s, 0x4);
    BYTE_AT(d, 0x5) = BYTE_AT(s, 0x5);
    BYTE_AT(d, 0x6) = BYTE_AT(s, 0x6);
    BYTE_AT(d, 0x7) = BYTE_AT(s, 0x7);
    BYTE_AT(d, 0x8) = BYTE_AT(s, 0x8);
    BYTE_AT(d, 0x9) = BYTE_AT(s, 0x9);
    BYTE_AT(d, 0xA) = BYTE_AT(s, 0xA);
    BYTE_AT(d, 0xB) = BYTE_AT(s, 0xB);
    BYTE_AT(d, 0xC) = BYTE_AT(s, 0xC);
    BYTE_AT(d, 0xD) = BYTE_AT(s, 0xD);
    BYTE_AT(d, 0xE) = BYTE_AT(s, 0xE);
    BYTE_AT(d, 0xF) = BYTE_AT(s, 0xF);
    FLOAT_AT(d, 0x10) = FLOAT_AT(s, 0x10);
    FLOAT_AT(d, 0x14) = FLOAT_AT(s, 0x14);
    FLOAT_AT(d, 0x18) = FLOAT_AT(s, 0x18);
    FLOAT_AT(d, 0x1C) = FLOAT_AT(s, 0x1C);
    FLOAT_AT(d, 0x20) = FLOAT_AT(s, 0x20);
    FLOAT_AT(d, 0x24) = FLOAT_AT(s, 0x24);
    FLOAT_AT(d, 0x28) = FLOAT_AT(s, 0x28);

    pf = (unsigned char*)arg1;
    do {
        f2 = FLOAT_AT(pf, 0x7C);
        if (BYTE_AT(arg1 + i, 0x79) != 0) {
            sub = *(unsigned char**)((unsigned char*)arg2 + 0x20);
            r = WORD_AT(sub, 0xEC) * 0x343FD;
            r += 0x269EC3;
            WORD_AT(sub, 0xEC) = r;
            float randomValue = (float)(r >> 16);
            f2 += ((float)BYTE_AT(arg1 + i, 0x79) *
                   (f2 * ((lbl_805A2CE4 * (randomValue / lbl_805A2CE0)) - lbl_805A2CE8))) /
                  lbl_805A2CEC;
        }
        *(unsigned char*)((unsigned int)d + i + 0x7A) = (int)(float)fn_8040036C(
            lbl_805A2CF0 * (f2 / lbl_805A2CF4) - lbl_805A2CF8) % 256;
        ++i;
        pf += 4;
    } while (i < 3);

    WORD_AT(arg0, 0x68) = WORD_AT(arg1, 0x68);
    FLOAT_AT(arg0, 0x2C) = FLOAT_AT(arg1, 0x2C);
    FLOAT_AT(arg0, 0x30) = FLOAT_AT(arg1, 0x30);
    FLOAT_AT(arg0, 0x44) = FLOAT_AT(arg1, 0x44);
    FLOAT_AT(arg0, 0x50) = FLOAT_AT(arg1, 0x50);
    FLOAT_AT(arg0, 0x54) = FLOAT_AT(arg1, 0x54);
    WORD_AT(arg0, 0x6C) = WORD_AT(arg1, 0x6C);
    FLOAT_AT(arg0, 0x34) = FLOAT_AT(arg1, 0x34);
    FLOAT_AT(arg0, 0x38) = FLOAT_AT(arg1, 0x38);
    FLOAT_AT(arg0, 0x48) = FLOAT_AT(arg1, 0x48);
    FLOAT_AT(arg0, 0x58) = FLOAT_AT(arg1, 0x58);
    FLOAT_AT(arg0, 0x5C) = FLOAT_AT(arg1, 0x5C);
    WORD_AT(arg0, 0x70) = WORD_AT(arg1, 0x70);
    FLOAT_AT(arg0, 0x3C) = FLOAT_AT(arg1, 0x3C);
    FLOAT_AT(arg0, 0x40) = FLOAT_AT(arg1, 0x40);
    FLOAT_AT(arg0, 0x4C) = FLOAT_AT(arg1, 0x4C);
    FLOAT_AT(arg0, 0x60) = FLOAT_AT(arg1, 0x60);
    FLOAT_AT(arg0, 0x64) = FLOAT_AT(arg1, 0x64);
    HALF_AT(arg0, 0x74) = HALF_AT(arg1, 0x74);
    BYTE_AT(arg0, 0x76) = BYTE_AT(arg1, 0x76);
    BYTE_AT(arg0, 0x77) = BYTE_AT(arg1, 0x77);
    BYTE_AT(arg0, 0x78) = BYTE_AT(arg1, 0x78);
}
