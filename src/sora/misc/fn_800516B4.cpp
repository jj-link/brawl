#pragma force_active on
extern "C" void *fn_8004E5C4(void *);
extern "C" void *g_GameGlobal;

extern "C" void fn_800516B4(unsigned int arg0) {
    unsigned char *temp_r3;

    temp_r3 = (unsigned char *)fn_8004E5C4(g_GameGlobal);
    temp_r3[0x2E5] = (unsigned char)(temp_r3[0x2E5] | arg0);
}
