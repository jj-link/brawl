#pragma force_active on
extern void fn_80242908(void *, int);

void fn_80245778(unsigned char *arg0, unsigned char *arg1, unsigned int arg2, unsigned int arg3, int arg4, unsigned int arg5, unsigned int arg6, unsigned int arg7) {
    unsigned char temp_r4;

    *(unsigned short *)(arg0 + 0x2) = 0x18;
    *(unsigned short *)(arg0 + 0x4) = 0;
    arg0[0x8] = 0x29;
    arg0[0x9] = 4;
    arg0[0xA] = 0x15;
    arg0[0xB] = arg1[5];
    arg0[0xC] = arg1[4];
    arg0[0xD] = arg1[3];
    arg0[0xE] = arg1[2];
    arg0[0xF] = arg1[1];
    temp_r4 = arg1[0];
    arg0[0x10] = temp_r4;
    arg0[0x11] = arg2;
    arg0[0x12] = (arg2 >> 8) & 0xff;
    arg0[0x13] = (arg2 >> 16) & 0xff;
    arg0[0x14] = arg2 >> 24;
    arg0[0x15] = arg3;
    arg0[0x16] = (arg3 >> 8) & 0xff;
    arg0[0x17] = (arg3 >> 16) & 0xff;
    arg0[0x18] = arg3 >> 24;
    arg0[0x19] = arg4;
    arg0[0x1A] = arg4 >> 8;
    arg0[0x1B] = arg5;
    arg0[0x1C] = (arg5 >> 8) & 0xff;
    arg0[0x1D] = arg6;
    arg0[0x1E] = arg7;
    arg0[0x1F] = (arg7 >> 8) & 0xff;
    fn_80242908(arg0, temp_r4);
}
