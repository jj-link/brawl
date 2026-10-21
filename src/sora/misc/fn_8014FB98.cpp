#pragma force_active on
extern "C" {
extern void *g_GameGlobal;

void fn_8014FB98(unsigned short arg0, unsigned char arg1, unsigned char arg2, unsigned char arg3);
}

void fn_8014FB98(unsigned short arg0, unsigned char arg1, unsigned char arg2, unsigned char arg3) {
    unsigned char *temp_r6;

    temp_r6 = *(unsigned char **)((char *)g_GameGlobal + 0x34);
    temp_r6[0x1B] = (unsigned char)(arg0 >> 8);
    temp_r6[0x1C] = (unsigned char)arg0;
    temp_r6[0x1D] = arg1;
    temp_r6[0x1E] = arg2;
}
