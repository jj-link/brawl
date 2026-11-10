#pragma force_active on
extern "C" void fn_8018CCF0(unsigned char*, unsigned short, unsigned int);
extern "C" void fn_80191DC0(int* arg0, int arg1, int arg2, unsigned int arg3, int arg4, int arg5) {
    int r7 = 0;
    int r8 = 0;
    int r9 = 5;
    int r10 = 5;
    int r11 = 0;
    int r0;
    unsigned char* base = (unsigned char*)(*arg0 + arg1 * 0x12);
    switch (arg3) {
    case 0: r9 = 0; r7 = 1; break;
    case 1: r9 = 1; r7 = 1; break;
    case 2: r9 = 3; r7 = 1; break;
    case 3: r9 = 4; r7 = 1; break;
    case 19: r9 = 2; break;
    case 20: r9 = 2; break;
    case 4: r9 = 5; break;
    case 5: r9 = 6; break;
    case 6: r9 = 7; break;
    case 7: r9 = 8; break;
    case 8: r9 = 9; break;
    case 9: r9 = 10; break;
    case 10: r9 = 11; break;
    case 11: r9 = 12; break;
    case 12: r10 = 0; break;
    case 13: r10 = 1; break;
    case 14: r10 = 2; break;
    case 15: r10 = 3; break;
    case 16: r10 = 4; break;
    case 17: r10 = 5; break;
    case 18: r10 = 6; break;
    }
    switch (arg2) {
    case 1: r0 = 0; break;
    case 0: r0 = 0; r8 = 1; break;
    case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
        r11 = arg2 - 2; r0 = 1; break;
    case 10:
        if ((int)arg3 == 0x13) r0 = 2;
        else r0 = 3;
        break;
    default: return;
    }
    unsigned int b = (((unsigned int)r11 << 15) | ((unsigned int)r10 << 12)) |
                     ((((unsigned int)r9 << 7) | ((unsigned int)r0 << 4)) |
                      (((unsigned int)r8 << 1) | ((unsigned int)r7 << 2)));
    fn_8018CCF0(base, (unsigned short)(arg1 + 0x1040), b);
    fn_8018CCF0(base + 9, (unsigned short)(arg1 + 0x1050),
                (unsigned int)(arg5 - 0x40) | (((unsigned int)arg4 & 0xFF) << 8));
}