#pragma force_active on

extern "C" {
extern void* g_GameGlobal;
void fn_80052F90(void);
}

void fn_80052F90(void) {
    unsigned char* src = *(unsigned char**)((char*)g_GameGlobal + 0x1c) + 2;
    unsigned char* dst = *(unsigned char**)((char*)g_GameGlobal + 0x48);
    int i;
    for (i = 0; i < 6; i++) {
        *dst++ = *src++;
    }

    src = *(unsigned char**)((char*)g_GameGlobal + 0x1c) + 8;
    dst = *(unsigned char**)((char*)g_GameGlobal + 0x4c);
    for (i = 0; i < 5; i++) {
        *dst++ = *src++;
    }
}
