#pragma force_active on
extern "C" {
extern void *g_GameGlobal;

void fn_8014F848(unsigned short arg0, signed char arg1, signed char arg2) {
    unsigned char *temp_r6;

    temp_r6 = *(unsigned char **)((char *)g_GameGlobal + 0x34);
    temp_r6[7] = (unsigned char)(arg0 >> 8);
    temp_r6[8] = (unsigned char)arg0;
    temp_r6[9] = (unsigned char)arg1;
    temp_r6[10] = (unsigned char)arg2;
}
}
