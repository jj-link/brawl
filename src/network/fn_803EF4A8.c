#pragma force_active on
typedef unsigned char u8;

extern float lbl_805A4B04;
extern float lbl_805A4B0C;
extern float lbl_805A4B10;

void fn_803EF4A8(u8 *arg0, int arg1) {
    float f;

    switch (arg1) {
    case 0xD0:
        *(int *)(arg0 + 0x7C) = 0;
        *(int *)(arg0 + 0x78) = *(int *)(arg0 + 0x78) + 1;
        break;
    case 0xD1:
        break;
    case 0xD2:
        arg0[0x3A] = 1;
        arg0[0x38] = 0;
        *(int *)(arg0 + 0x78) = 0;
        *(int *)(arg0 + 0x7C) = 0;
        break;
    case 0xD4:
        break;
    case 0xDC:
        *(int *)(arg0 + 0x3C) = 0;
        break;
    case 0xDD:
        *(int *)(arg0 + 0x3C) = 0;
        break;
    case 0xDE:
        *(int *)(arg0 + 0x3C) = 0;
        break;
    case 0xFA:
        *(int *)(arg0 + 0x60) = 0xFA;
        break;
    case 0xFB:
        *(int *)(arg0 + 0x60) = 0xFB;
        break;
    case 0xFC:
        *(int *)(arg0 + 0x60) = 0xFC;
        break;
    case 0xFD:
        *(int *)(arg0 + 0x60) = 0xFD;
        return;
    case 0x104:
        f = lbl_805A4B04;
        *(float *)(arg0 + 0x14) = f;
        *(float *)(arg0 + 0x28) = f;
        break;
    case 0x105:
        f = lbl_805A4B0C;
        *(float *)(arg0 + 0x14) = f;
        *(float *)(arg0 + 0x28) = f;
        break;
    case 0x106:
        f = lbl_805A4B10;
        *(float *)(arg0 + 0x14) = f;
        *(float *)(arg0 + 0x28) = f;
        break;
    case 0x12B:
        break;
    }

    if (arg1 >= 0xE6 && arg1 <= 0xF1) {
        *(int *)(arg0 + 0x40) = arg1 - 0xE5;
        *(int *)(arg0 + 0x44) = 1;
    }
    if (arg1 >= 0x12C && arg1 <= 0x16B) {
        *(int *)(arg0 + 0x48) = arg1 - 0x12C;
    }
}
